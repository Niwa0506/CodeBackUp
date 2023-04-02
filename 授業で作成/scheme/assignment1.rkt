(define TREE '(1 (2 (3 4)) 6 (7 8 9)) )

(define tree-member?
  (lambda(tree val)
    (cond ((null? tree) #f)         ; tree が空の時 (= 見つからなかった)
          ((pair? tree)
                        (or (tree-member? (car tree) val) (tree-member? (cdr tree) val)))
                         ; tree が部分木の時 (まだ値の比較はできない)
          (else         (equal? tree val))  ; tree 葉の時 (ここで val と比較する)
    )))