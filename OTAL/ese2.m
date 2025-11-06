########

Each function separately

######

%% ============================================================
% Single Function Optimization - Standard vs Hybrid PSO
% Author: Mihir Hebalkar
% ============================================================
clc; clear; close all;

%% ---------------------- DEFINE TEST FUNCTIONS ----------------------
benchmarks = {
    'Sphere',      @(x) sum(x.^2), [-100, 100];
    'Rosenbrock',  @(x) sum(100*(x(2:end)-x(1:end-1).^2).^2 + (x(1:end-1)-1).^2), [-30, 30];
    'Ackley',      @(x) -20*exp(-0.2*sqrt(mean(x.^2))) - exp(mean(cos(2*pi*x))) + 20 + exp(1), [-32, 32];
};

%% ---------------------- CHOOSE ONE FUNCTION ----------------------
choice = 2;   % <-- Change index (1, 2, 3, etc.) to pick the function

name = benchmarks{choice,1};
func = benchmarks{choice,2};
bounds = benchmarks{choice,3};

%% ---------------------- PARAMETERS ----------------------
dim = 30;
n_particles = 30;
max_iter = 300;
n_runs = 3;

fprintf('\n=== Running PSO on %s Function ===\n', name);

curve_std = zeros(n_runs, max_iter);
curve_hyb = zeros(n_runs, max_iter);

for r = 1:n_runs
    [~, curve_std(r,:)] = standard_pso(func, dim, bounds, n_particles, max_iter);
    [~, curve_hyb(r,:)] = hybrid_pso(func, dim, bounds, n_particles, max_iter);
end

avg_std = mean(curve_std);
avg_hyb = mean(curve_hyb);

%% ---------------------- PLOT BOTH ----------------------
figure('Name', name, 'NumberTitle', 'off');
semilogy(avg_std, 'b-', 'LineWidth', 2); hold on;
semilogy(avg_hyb, 'r-', 'LineWidth', 2);
grid on;
xlabel('Iteration'); ylabel('Best Cost (log scale)');
title(['Convergence Comparison: ', name]);
legend('Standard PSO', 'Hybrid PSO', 'Location', 'best');

imp = ((avg_std(end) - avg_hyb(end)) / avg_std(end)) * 100;
fprintf('Final (Standard): %.3e\n', avg_std(end));
fprintf('Final (Hybrid):   %.3e\n', avg_hyb(end));
fprintf('Improvement:      %.2f%%\n', imp);

fprintf('\n=== Optimization Completed ===\n');

%% ---------------------- FUNCTIONS ----------------------
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
            vel(i,:) = w*vel(i,:) + c1*r1.*(pbest(i,:) - pos(i,:)) + c2*r2.*(gbest - pos(i,:));
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
            vel(i,:) = beta*vel(i,:) + alpha*rand(1,dim).*(gbest - pos(i,:)) + ...
                w*(c1*r1.*(pbest(i,:) - pos(i,:)) + c2*r2.*(gbest - pos(i,:)));
            pos(i,:) = max(min(pos(i,:) + vel(i,:), ub), lb);

            if rand < mutation_prob
                m = randi(dim);
                pos(i,m) = lb + (ub-lb)*rand();
            end

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





########

Two different figures

######



%% ============================================================
% Two-Figure Visualization for Standard vs Hybrid PSO
% Author: Mihir Hebalkar
% ============================================================
clc; clear; close all;

%% ---------------------- DEFINE TEST FUNCTION ----------------------
name = 'Ackley';
f = @(x) -20*exp(-0.2*sqrt(mean(x.^2))) - exp(mean(cos(2*pi*x))) + 20 + exp(1);
bounds = [-32, 32];

%% ---------------------- PARAMETERS ----------------------
dim = 30; 
n_particles = 30; 
max_iter = 300; 
n_runs = 3;

fprintf('\n=== Optimizing %s Function ===\n', name);

curve_std = zeros(n_runs, max_iter);
curve_hyb = zeros(n_runs, max_iter);

for r = 1:n_runs
    [~, curve_std(r,:)] = standard_pso(f, dim, bounds, n_particles, max_iter);
    [~, curve_hyb(r,:)] = hybrid_pso(f, dim, bounds, n_particles, max_iter);
end

avg_std = mean(curve_std);
avg_hyb = mean(curve_hyb);

%% ---------------------- PLOT IN TWO FIGURES ----------------------

% ---- Figure 1: Standard PSO ----
figure('Name', [name, ' - Standard PSO'], 'NumberTitle', 'off');
semilogy(avg_std, 'b-', 'LineWidth', 2);
grid on;
xlabel('Iteration'); ylabel('Best Cost (log scale)');
title(['Convergence of Standard PSO on ', name]);
legend('Standard PSO', 'Location', 'best');

% ---- Figure 2: Hybrid PSO ----
figure('Name', [name, ' - Hybrid PSO'], 'NumberTitle', 'off');
semilogy(avg_hyb, 'r-', 'LineWidth', 2);
grid on;
xlabel('Iteration'); ylabel('Best Cost (log scale)');
title(['Convergence of Hybrid PSO on ', name]);
legend('Hybrid PSO', 'Location', 'best');

%% ---------------------- RESULTS ----------------------
imp = ((avg_std(end) - avg_hyb(end)) / avg_std(end)) * 100;
fprintf('Final (Standard): %.3e\n', avg_std(end));
fprintf('Final (Hybrid):   %.3e\n', avg_hyb(end));
fprintf('Improvement:      %.2f%%\n', imp);

fprintf('\n=== Optimization Completed ===\n');

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

            % Random mutation
            if rand < mutation_prob
                m = randi(dim);
                pos(i,m) = lb + (ub-lb)*rand();
            end

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
