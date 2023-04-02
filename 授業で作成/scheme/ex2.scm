(define alphabet
  (read(open-input-file "/class/scheme/alphabet")))
(define tokugawa
  (read(open-input-file "/class/scheme/tokugawa")))
;1
(define get-depth
  (lambda (kakeizu n)
    (cond        ((= n 1)  (map car (cdr kakeizu)))
                 (else (apply append (map (lambda(x) (get-depth x (- n 1))) (cdr kakeizu))))
    )
  )
)
;2
(define get-cousin
  (lambda (kakeizu name)
    (get-depth kakeizu (search kakeizu name 0))
  )
)

(define search
  (lambda (kakeizu name n)
    (cond        ((equal? name (car kakeizu)) n)
                 ((null? (cdr kakeizu)) 0)
                 (else (apply + (map(lambda(x) (search x name (+ 1 n))) (cdr kakeizu))))
    )
  )
)
;3
(define get-path
  (lambda (kakeizu name)

    (cond
                 ((equal? name (car kakeizu)) (cons name '()))
                 ((null? (cdr kakeizu)) '())
                 (else (apply append (map (lambda(x) (if (equal? (get-path x name) '()) '()
                                                     (append (cons (car kakeizu) (get-path x name)))
                                                      )) (cdr kakeizu))))
    )             
  ) 
)
          
          