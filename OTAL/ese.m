%% ============================================================
% Simplified Standard PSO vs Hybrid PSO
% Author: Mihir Hebalkar
% ============================================================
clc; clear; close all;

%% ---------------------- DEFINE TEST FUNCTIONS ----------------------
benchmarks = {
    'Sphere',      @(x) sum(x.^2), ...
    [-100, 100];
    'Rosenbrock',  @(x) sum(100*(x(2:end)-x(1:end-1).^2).^2 + (x(1:end-1)-1).^2), ...
    [-30, 30];
    'Sum Squares', @(x) sum((1:length(x)).*x.^2), ...
    [-10, 10];
    'Quartic',     @(x) sum((1:length(x)).*x.^4), ...
    [-1.28, 1.28];
    'Zakharov',    @(x) sum(x.^2) + (sum(0.5*(1:length(x)).*x))^2 + (sum(0.5*(1:length(x)).*x))^4, ...
    [-5, 10];
    'Rastrigin',   @(x) 10*length(x) + sum(x.^2 - 10*cos(2*pi*x)), ...
    [-5.12, 5.12];
    'Ackley',      @(x) -20*exp(-0.2*sqrt(mean(x.^2))) - exp(mean(cos(2*pi*x))) + 20 + exp(1), ...
    [-32, 32];
    'Griewank',    @(x) sum(x.^2)/4000 - prod(cos(x./sqrt(1:length(x)))) + 1, ...
    [-600, 600];
    'Schwefel',    @(x) 418.9829*length(x) - sum(x.*sin(sqrt(abs(x)))), ...
    [-500, 500];
    'Alpine',      @(x) sum(abs(x.*sin(x) + 0.1*x)), ...
    [-10, 10];
};

%% ---------------------- PARAMETERS ----------------------
dim = 30;
n_particles = 30;
max_iter = 300;
n_runs = 3;   % repeat to average out randomness

fprintf('\n=== Starting PSO Optimization Comparison ===\n');

%% ---------------------- MAIN LOOP ----------------------
for f = 1:size(benchmarks,1)
    name = benchmarks{f,1};
    func = benchmarks{f,2};
    bounds = benchmarks{f,3};
    fprintf('\nFunction %d: %s\n', f, name);

    curve_std = zeros(n_runs, max_iter);
    curve_hyb = zeros(n_runs, max_iter);

    for r = 1:n_runs
        [~, curve_std(r,:)] = standard_pso(func, dim, bounds, n_particles, max_iter);
        [~, curve_hyb(r,:)] = hybrid_pso(func, dim, bounds, n_particles, max_iter);
    end

    avg_std = mean(curve_std);
    avg_hyb = mean(curve_hyb);

    % Plot comparison
    figure('Name', name, 'NumberTitle', 'off');
    semilogy(avg_std, 'b-', 'LineWidth', 2); hold on;
    semilogy(avg_hyb, 'r-', 'LineWidth', 2);
    grid on; xlabel('Iteration'); ylabel('Best Cost (log scale)');
    title(['Convergence Comparison: ', name]);
    legend('Standard PSO', 'Hybrid PSO', 'Location', 'best');

    % Show improvement
    imp = ((avg_std(end) - avg_hyb(end)) / avg_std(end)) * 100;
    fprintf('  Final (Standard): %.3e\n', avg_std(end));
    fprintf('  Final (Hybrid):   %.3e\n', avg_hyb(end));
    fprintf('  Improvement:      %.2f%%\n', imp);
end

fprintf('\n=== All Functions Optimized Successfully ===\n');

%% ============================================================
%                 STANDARD PSO FUNCTION
%% ============================================================
function [gbest, curve] = standard_pso(f, dim, bounds, n, max_iter)
    lb = bounds(1); ub = bounds(2);
    w_max = 0.9; w_min = 0.4; c1 = 2; c2 = 2;

    pos = lb + (ub-lb)*rand(n, dim);
    vel = zeros(n, dim);
    fit = arrayfun(@(i) f(pos(i,:)), 1:n)';
    pbest = pos; pbest_fit = fit;
    [gbest_fit, idx] = min(fit); gbest = pos(idx,:);
    curve = zeros(1, max_iter);

    for t = 1:max_iter
        w = w_max - (w_max - w_min)*t/max_iter;
        for i = 1:n
            r1 = rand(1,dim); r2 = rand(1,dim);
            vel(i,:) = w*vel(i,:) + ...
                       c1*r1.*(pbest(i,:) - pos(i,:)) + ...
                       c2*r2.*(gbest - pos(i,:));
            pos(i,:) = max(min(pos(i,:) + vel(i,:), ub), lb);

            fit(i) = f(pos(i,:));
            if fit(i) < pbest_fit(i)
                pbest_fit(i) = fit(i); pbest(i,:) = pos(i,:);
            end
            if fit(i) < gbest_fit
                gbest_fit = fit(i); gbest = pos(i,:);
            end
        end
        curve(t) = gbest_fit;
    end
end

%% ============================================================
%                 HYBRID (ACCELERATED) PSO FUNCTION
%% ============================================================
function [gbest, curve] = hybrid_pso(f, dim, bounds, n, max_iter)
    lb = bounds(1); ub = bounds(2);
    w_max = 0.9; w_min = 0.3;
    c1i = 2.5; c1f = 0.5; c2i = 0.5; c2f = 2.5;
    alpha = 0.4; beta = 0.9; mutation_prob = 0.1;

    pos = lb + (ub-lb)*rand(n, dim);
    vel = zeros(n, dim);
    fit = arrayfun(@(i) f(pos(i,:)), 1:n)';
    pbest = pos; pbest_fit = fit;
    [gbest_fit, idx] = min(fit); gbest = pos(idx,:);
    curve = zeros(1, max_iter);

    for t = 1:max_iter
        w = w_max - (w_max - w_min)*(t/max_iter)^2;
        c1 = c1i - (c1i - c1f)*t/max_iter;
        c2 = c2i + (c2f - c2i)*t/max_iter;

        for i = 1:n
            r1 = rand(1,dim); r2 = rand(1,dim);
            vel(i,:) = beta*vel(i,:) + ...
                       alpha*rand(1,dim).*(gbest - pos(i,:)) + ...
                       w*(c1*r1.*(pbest(i,:) - pos(i,:)) + ...
                          c2*r2.*(gbest - pos(i,:)));

            pos(i,:) = max(min(pos(i,:) + vel(i,:), ub), lb);


            fit(i) = f(pos(i,:));
            if fit(i) < pbest_fit(i)
                pbest_fit(i) = fit(i); pbest(i,:) = pos(i,:);
            end
            if fit(i) < gbest_fit
                gbest_fit = fit(i); gbest = pos(i,:);
            end
        end
        curve(t) = gbest_fit;
    end
end
