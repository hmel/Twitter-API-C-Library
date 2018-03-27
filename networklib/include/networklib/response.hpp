#ifndef RESPONSE_HPP
#define RESPONSE_HPP
#include <memory>
#include <string>

#include <boost/property_tree/ptree.hpp>

namespace tal {

// Change this to Response.
class Response {
   public:
    Response() = default;
    explicit Response(std::string message_body);
    explicit operator std::string() const;
    enum Type { Unknown, Event, User };
    std::string get(const std::string& key) const;
    std::string json() const { return message_body_; }
    boost::property_tree::ptree& ptree();
    boost::property_tree::ptree ptree() const;

   private:
    Type object_type_;
    void deduce_type();
    std::string message_body_;
    mutable std::unique_ptr<boost::property_tree::ptree> json_tree_ptr_;

    void build_ptree() const;
};

inline std::ostream& operator<<(std::ostream& os, const Response& m) {
    return os << static_cast<std::string>(m);
}

}  // namespace tal
#endif  // RESPONSE_HPP