/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {

    return {
        x: init,
        increment: function () {
            this.x++;
            return this.x;
        },

        decrement: function () {
            this.x--;
            return this.x;
        },

        reset: function () {
            this.x = init
            return this.x;
        }
    }

};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */