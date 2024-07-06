/**
 * @param {number} n
 * @return {Function} counter
 */
var count = 0;

var createCounter = function (n) {
    let flag = 1;
    return function () {
        if(flag) {
            flag = 0;
            count = n;
            return n;
        } else {
            count = count + 1; 
            return count;
        }

    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */