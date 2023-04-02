(define-syntax stream-cons
    (syntax-rules ()
        ((_ x y) (cons x (delay y)))
    ))

(define-syntax stream-car
    (syntax-rules ()
        ((_ x) (car x ))
    ))

(define-syntax stream-cdr
    (syntax-rules ()
        ((_ x) (force (cdr x)))
    ))

(define (natural-number n)
   (stream-cons n (natural-number (+ n 1))))
(define stream-ref
  (lambda (s n)
    (if (= n 0)
        (stream-car s)
        (stream-ref (stream-cdr s) (- n 1)))
  )
)

(define head (lambda (n L)
  (if (<= n 0) '()
      (cons (stream-car L) (head (- n 1) (stream-cdr L)))
      )))

(define numbers (lambda ()
  (letrec ((stream
              (lambda (n) (stream-cons n (stream (+ n 1))))
          ))
          (stream 2))))

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

(define primes (sieve (natural-number 2)))