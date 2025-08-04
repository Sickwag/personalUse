let message = 'hello world'
console.log(message)

interface User {
    name: string,
    id: number
}

// const user: User = {
//     name:"jackal",
//     id:0,
// }

class UserAccount {
    name: string = "hello";
    id: number;
    constructor(name: string, id: number) {
        this.name = name;
        this.id = id;
    }
}

const user: User = new UserAccount("jackal", 3);
console.log(user);

interface Backpack<Type> {
    contents: Type;
    add: (obj: Type) => void;
    get: () => Type;
}

declare const backpack: Backpack<string>; // 就像C++中的函数或者变量声明一样，提前告诉编译器这里有一个名为backpack的变量
// backpack.add("hello");
const stringBackpack: Backpack<string> = {
    contents: "jackal",
    add(obj: string) {
        this.contents = obj;
    },
    get(): string {
        return this.contents;
    }
};
const object = stringBackpack.get();
console.log(object)


const select = document.querySelector("select");
const para = document.querySelector("p");

select!.addEventListener("change", setWeather);

function setWeather() {
    const choice = select!.value;

    if (choice === "sunny") {
        para!.textContent = "阳光明媚。穿上短裤吧！去海滩，或公园，吃个冰淇淋。";
    } else if (choice === "rainy") {
        para!.textContent = "外面下着雨；带上雨衣和雨伞，不要在外面呆太久。";
    } else if (choice === "snowing") {
        para!.textContent =
            "大雪纷飞，天寒地冻！最好呆在家里喝杯热巧克力，或者去堆个雪人。";
    } else if (choice === "overcast") {
        para!.textContent =
            "虽然没有下雨，但天空灰蒙蒙的，随时都可能变天，所以要带一件雨衣以防万一。";
    } else {
        para!.textContent = "";
    }
}
