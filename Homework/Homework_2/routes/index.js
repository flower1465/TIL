const router = require("express").Router();
const user = require("./user");
const post = require("./posts");
const middleware = require("../middleware/token");

router.use("/user", user);
router.use("/post", post);

module.exports = router;
