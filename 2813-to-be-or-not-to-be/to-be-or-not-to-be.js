/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    function toBe(x) {
        if (x === val) return true
        else throw new Error("Not Equal")
    }

    function notToBe(x) {
        if (x !== val) return true
        else throw new Error("Equal")

    }

    return {
        toBe, notToBe
    }
};
