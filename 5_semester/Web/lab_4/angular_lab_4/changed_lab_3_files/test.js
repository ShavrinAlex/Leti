import supertest from "supertest";
import { router } from "../router";


describe("test", () => {
    test("login", () => {
        supertest(router)
            .get("/authorization/login?email=apshavrin@stud.etu.ru&password=12345")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })
    
    test("signup", () => {
        supertest(router)
            .post("/authorization/signup")
            .send({
                "userrname": 'Patrikeev Semen Igorevitch',
                "email": 'sipatrikeev@mail.ru',
                "birth": '2002-01-01',
                "password": '000'
            })
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

    test("account", () => {
        supertest(router)
            .get("/account?id=0")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

    test("user_page", () => {
        supertest(router)
            .get("/account/user_page?id=2")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

    test("friends", () => {
        supertest(router)
            .get("/account/friends?id=1")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

    test("news", () => {
        supertest(router)
            .get("/account/news?id=5")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

    test("messages", () => {
        supertest(router)
            .get("/account/messages?id=6")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

    test("dialog", () => {
        supertest(router)
            .get("/account/dialog?dialog_id=0")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

    test("go to dialog", () => {
        supertest(router)
            .get("/account/friends/go_to_dialog?user_id=0&friend_id=1")
            .then(response => {
                expect(response.statusCode).toBe(200);
            });
    })

});