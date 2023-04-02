(define stream-car
  (lambda (st) (car st)))

(define stream-cdr
  (lambda (st)
    (force (cdr st)))
)

(define stream-ref
  (lambda (s n)
    (if (= n 0)
        (stream-car s)
        (stream-ref (stream-cdr s) (- n 1)))
  )
)
(define main
  (lambda (n)
    (map (lambda (x) (stream-ref primes x)) (range 0 n))
        ))

(define range
  (lambda (s e)
    (if (< s (- e 1))
    (cons s (range (+ s 1) e))
    (list (- e 1))
    )
  )
)

(define integers-starting-from
  (lambda (x)
    (cons x (delay (integers-starting-from (+ x 1))))))

(define stream-filter
  (lambda (pred ls)
       (if (null? ls)
           '()
         (let ((obj (stream-car ls)))
           (if (pred obj)
               (cons obj (delay (stream-filter pred (stream-cdr ls))))
               (stream-filter pred (stream-cdr ls)))))))

(define divisible?
  (lambda (x y)
    (= (remainder x y) 0)
  )
)

(define sieve
  (lambda (stream)
    (cons (stream-car stream)
          (delay (sieve (stream-filter
                         (lambda (x) (not (divisible? x (stream-car stream)))) (stream-cdr stream)))))))

(define primes (sieve (integers-starting-from 2)))