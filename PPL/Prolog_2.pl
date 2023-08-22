/*Medical*/
/*FACTS*/

symptom(a,sneezing).
symptom(a,fever).
symptom(a,headache).
symptom(a,sore_throat).

symptom(b,rash).
symptom(b,sneezing).
symptom(b,fever).
symptom(b,body_ache).
symptom(b,rash).

symptom(c,chills).
symptom(c,fever).
symptom(c,body_ache).

symptom(d,fever).
symptom(d,rash).
symptom(d,headache).
symptom(d,cough).
symptom(d,loss_of_taste).

/*Rules*/

disease(X,corona):-symptom(X,fever),symptom(X,cough),symptom(X,loss_of_taste),!.

disease(X,cold):-symptom(X,headache),symptom(X,sneezing),symptom(X,sore_throat),!.

disease(X,flu):-symptom(X,chills),symptom(X,fever),symptom(X,headache),!.

disease(X,allergy):-symptom(X,sneezing),symptom(X,rash),!.
