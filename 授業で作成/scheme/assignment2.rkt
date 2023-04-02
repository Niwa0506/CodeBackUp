(define TREE '(1 (2 (3 4)) 6 (7 8 9)) )


(define map-tree
   (lambda (f l)
     (cond ((null? l) '())         ; tree が空の時 (= 見つからなかった)
           ((pair? l)   (cons
                        (map-tree f (car l))
                        (map-tree f (cdr l))
                        )
                        )
                         ; tree が部分木の時 (まだ値の比較はできない)
          (else         cons(f l); tree 葉の時 (ここで val と比較する)
                        )
    )))