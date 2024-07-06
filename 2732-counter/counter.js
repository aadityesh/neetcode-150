// var count = 0;
// var createCounter = function (n) {
//     let flag = 1;
//     return function () {
//         if(flag) {
//             flag = 0;
//             count = n;
//             return n;
//         } else {
//             count = count + 1; 
//             return count;
//         }

//     };
// };

var createCounter = function (n) {
    return function () {
        return n++;
    };
};
