
class Singleton {
    constructor() {
        if (!Singleton.instance) {
            Singleton.instance = this
        }
        return Singleton.instance
    }
    getInstance() {
        return this
    }
    inputInstance(key,value){
        this[key] = value
    }
}
const a = new Singleton()
const b = new Singleton() 
a.inputInstance("aaa",10);
console.log(b.getInstance()) // true 