const router = require("express")();
const user = require("./user");
const middleware = require("../middleware/token");

router.use("/user", user);

module.exports = router;
