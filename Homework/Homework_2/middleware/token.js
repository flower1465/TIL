const jwt = require("jsonwebtoken");

const tokenMiddleware = async (req, res, next) => {
  const token = req.headers["access-token"];
  if (!token) {
    res.status(403).json({ message: "로그인 되어있지 않음" });
  }
  try {
    req.decoded = await jwt.verify(token, req.app.get("jwt-secret"));
    next();
  } catch (err) {
    res.status(403).json({
      message: "로그인 되어있지 않음",
    });
  }
};

module.exports = tokenMiddleware;
