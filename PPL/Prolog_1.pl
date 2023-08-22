/*Family Tree*/

/*Facts*/

male(mihir).
male(bro).
male(gra).
male(mgra).
male(unc).
male(fa).

female(mo).
female(sis).
female(gram).
female(mgram).
female(au).

parent_of(fa,mihir).
parent_of(mo,mihir).
parent_of(fa,bro).
parent_of(mo,bro).
parent_of(fa,sis).
parent_of(mo,sis).

parent_of(gra,fa).
parent_of(gra,unc).
parent_of(gram,fa).
parent_of(gram,unc).

parent_of(mgra,mo).
parent_of(mgra,au).
parent_of(mgram,mo).
parent_of(mgram,au).


/*Rules*/
father_of(X,Y):-male(X),parent_of(X,Y).
mother_of(X,Y):-female(X),parent_of(X,Y).
grandfather_of(X,Y):-male(X),parent_of(X,Z),parent_of(Z,Y).
grandmother_of(X,Y):-female(X),parent_of(X,Z),parent_of(Z,Y).
sister_of(X,Y):-female(X),father_of(F,Y),father_of(F,X),X\=Y.
sister_of(X,Y):-female(Y),father_of(F,Y),father_of(F,X),X\=Y.
brother_of(X,Y):-male(X),father_of(F,Y),father_of(F,X),X\=Y.
brother_of(X,Y):-male(Y),father_of(F,Y),father_of(F,X),X\=Y.
aunt_of(X,Y):-female(X),parent_of(Z,Y),sister_of(Z,X),!. /*To stop backtracking*/
uncle_of(X,Y):-male(X),parent_of(Z,Y),brother_of(Z,X),!.
sibling_of(X,Y):-male(X);female(X),father_of(F,Y),father_of(F,X),X\=Y.
sibling_of(X,Y):-male(Y);female(Y),father_of(F,Y),father_of(F,X),X\=Y.
