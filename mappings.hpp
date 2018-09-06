#include <string>

namespace eosio {

const static std::string elastic_mappings = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "type": {
                    "type": "keyword"
                },
                "createAt": {
                    "type": "date"
                },
                "updateAt": {
                    "type": "date"
                },
                "block": {
                    "enabled": false
                },
                "block_header_state": {
                    "enabled": false
                },
                "abi": {
                    "enabled": false
                },
                "actions": {
                    "enabled": false
                },
                "action_traces": {
                    "enabled": false
                },
                "receipt": {
                    "enabled": false
                },
                "act": {
                    "enabled": false
                }
            }
        }
    }
}
)";

}