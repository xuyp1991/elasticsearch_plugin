#include <string>

namespace eosio {

const static std::string accounts_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "name": {
                    "type": "text"
                },
                "creator": {
                    "type": "text"
                },
                "pub_keys": {
                    "type": "nested"
                },
                "account_controls": {
                    "type": "nested"
                },
                "abi": {
                    "enabled": false
                },
                "account_create_time": {
                    "type": "date"
                },
                "createAt": {
                    "type": "date"
                },
                "updateAt": {
                    "type": "date"
                }
            }
        }
    }
}
)";

static const std::string blocks_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "block": {
                    "type": "object",
                    "properties": {
                        "header_extensions" :{"type": "nested"},
                        "new_producers" :{"enabled": false},
                        "previous" :{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "block_extensions" :{"type": "nested"},
                        "schedule_version" :{"type": "long"},
                        "producer" :{"type": "text"},
                        "transaction_mroot" :{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "producer_signature" :{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "transactions" :{"enabled": false},
                        "confirmed" : {"type": "long"},
                        "action_mroot" :{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "timestamp" :{"type": "date"}
                    }
                },
                "block_id": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "block_num": {
                    "type": "long"
                },
                "createAt": {
                    "type": "date"
                },
                "irreversible": {
                    "type": "boolean"
                },
                "updateAt": {
                    "type": "date"
                },
                "validated": {
                    "type": "boolean"
                }
            }
        }
    }
}
)";




// static const std::string trans_mapping = R"(
// {
//     "mappings": {
//         "_doc": {
//             "properties": {
//                 "createAt": {
//                     "type": "date"
//                 },
//                 "updateAt": {
//                     "type": "date"
//                 },
//                 "actions": {
//                     "enabled": false
//                 }
//             }
//         }
//     }
// }
// )";

static const std::string trans_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "accepted": {
                    "type": "boolean"
                },
                "actions": {
                    "type": "object",
                    "properties": {
                        "account": {"type": "text"},
                        "name": {"type": "text"},
                        "authorization": {
                            "type": "nested",
                            "properties": {
                                "actor":{
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                },
                                "permission": {
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                }
                            }
                        },
                        "data": {"enabled": false}
                    }
                },
                "block_id": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "block_num": {
                    "type": "long"
                },
                "createAt": {
                    "type": "date"
                },
                "delay_sec": {
                    "type": "long"
                },
                "expiration": {
                    "type": "date"
                },
                "fee": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "implicit": {
                    "type": "boolean"
                },
                "irreversible": {
                    "type": "boolean"
                },
                "max_cpu_usage_ms": {
                    "type": "long"
                },
                "max_net_usage_words": {
                    "type": "long"
                },
                "ref_block_num": {
                    "type": "long"
                },
                "ref_block_prefix": {
                    "type": "long"
                },
                "scheduled": {
                    "type": "boolean"
                },
                "signatures": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "signing_keys": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "trx_id": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "updateAt": {
                    "type": "date"
                }
            }
        }
    }
}
)";


// static const std::string block_states_mapping = R"(
// {
//     "mappings": {
//         "_doc": {
//             "properties": {
//                 "createAt": {
//                     "type": "date"
//                 },
//                 "updateAt": {
//                     "type": "date"
//                 },
//                 "block_header_state": {
//                     "enabled": false
//                 }
//             }
//         }
//     }
// }
// )";

static const std::string block_states_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "block_header_state": {
                    "properties": {
                        "active_schedule":{"enabled": false},
                        "in_current_chain":{"type": "boolean"},
                        "pending_schedule_lib_num":{"type": "long"},
                        "dpos_proposed_irreversible_blocknum":{"type": "long"},
                        "dpos_irreversible_blocknum":{"type": "long"},
                        "pending_schedule":{"enabled": false},
                        "producer_to_last_produced":{"enabled": false},
                        "pending_schedule_hash":{
                            "type": "text",
                                "fields": {
                                    "keyword": {
                                        "type": "keyword",
                                        "ignore_above": 256
                                    }
                                }
                        },
                        "blockroot_merkle":{"enabled": false},
                        "confirm_count":{"enabled": false},
                        "confirmations":{"enabled": false},
                        "block_num":{"type": "long"},
                        "validated":{"type": "boolean"},
                        "bft_irreversible_blocknum":{"type": "long"},
                        "header":{"enabled": false},
                        "producer_to_last_implied_irb":{"enabled": false},
                        "block_signing_key":{
                            "type": "text",
                                "fields": {
                                    "keyword": {
                                        "type": "keyword",
                                        "ignore_above": 256
                                    }
                                }
                        },
                        "block":{"enabled": false},
                        "id":{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        }
                    }
                },
                "block_id": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "block_num": {
                    "type": "long"
                },
                "createAt": {
                    "type": "date"
                },
                "irreversible": {
                    "type": "boolean"
                },
                "updateAt": {
                    "type": "date"
                },
                "validated": {
                    "type": "boolean"
                }
            }
        }
    }
}
)";

static const std::string trans_traces_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "createAt": {
                    "type": "date"
                },
                "updateAt": {
                    "type": "date"
                },
                "action_traces": {
                    "properties": {
                        "receipt":{
                            "type": "object",
                            "properties": {
                                "receiver":{
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                },
                                "act_digest":{
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                },
                                "global_sequence":{"type": "long"},
                                "recv_sequence":{"type": "long"},
                                "auth_sequence":{"enabled": false},
                                "code_sequence":{"type": "long"},
                                "abi_sequence":{"type": "long"}
                            }
                        },
                        "act":{
                            "type": "object",
                            "properties": {
                                "account":{
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                },
                                "name":{
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                },
                                "authorization":{"enabled": false},
                                "data":{"enabled": false}
                            }
                        },
                        "elapsed":{"type": "long"},
                        "cpu_usage":{"type": "long"},
                        "console":{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "total_cpu_usage":{"type": "long"},
                        "trx_id":{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "inline_traces":{"enabled": false}
                    }
                },
                "failed_dtrx_trace": {
                    "enabled": false
                },
                "except": {
                    "enabled": false
                }
            }
        }
    }
}
)";

// static const std::string action_traces_mapping = R"(
// {
//     "mappings": {
//         "_doc": {
//             "properties": {
//                 "createAt": {
//                     "type": "date"
//                 },
//                 "updateAt": {
//                     "type": "date"
//                 },
//                 "receipt": {
//                     "enabled": false
//                 },
//                 "act": {
//                     "enabled": false
//                 },
//                 "account_ram_deltas": {
//                     "enabled": false
//                 }
//             }
//         }
//     }
// }
// )";
static const std::string action_traces_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "account_ram_deltas": {
                    "type": "object",
                    "enabled": false
                },
                "act": {
                    "type": "object",
                    "properties": {
                        "account" :{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "name" :{
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "authorization" :{"enabled": false},
                        "data" :{"enabled": false}
                    }
                },
                "console": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "cpu_usage": {
                    "type": "long"
                },
                "createAt": {
                    "type": "date"
                },
                "elapsed": {
                    "type": "long"
                },
                "receipt": {
                    "type": "object",
                    "enabled": false
                },
                "total_cpu_usage": {
                    "type": "long"
                },
                "trx_id": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "updateAt": {
                    "type": "date"
                }
            }
        }
    }
}
)";

static const std::string vote_action_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "account": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "name": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "authorization":{"enabled":false},
                "data":{
                    "properties": {
                        "voter": {
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "bpname": {
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "stake": {
                            "properties":{
                                "amount":{"type":"float"},
                                "symbol":{
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                }
                            }
                        }
                    }
                },
                "hex_data":{
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "createAt": {
                    "type": "date"
                }
            }
        }
    }
}
)";

static const std::string transfer_action_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "account": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "name": {
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "authorization":{"enabled":false},
                "data":{
                    "properties": {
                        "from": {
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "to": {
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        },
                        "quantity": {
                            "properties":{
                                "amount":{"type":"float"},
                                "symbol":{
                                    "type": "text",
                                    "fields": {
                                        "keyword": {
                                            "type": "keyword",
                                            "ignore_above": 256
                                        }
                                    }
                                }
                            }
                        },
                        "memo": {
                            "type": "text",
                            "fields": {
                                "keyword": {
                                    "type": "keyword",
                                    "ignore_above": 256
                                }
                            }
                        }
                    }
                },
                "hex_data":{
                    "type": "text",
                    "fields": {
                        "keyword": {
                            "type": "keyword",
                            "ignore_above": 256
                        }
                    }
                },
                "createAt": {
                    "type": "date"
                }
            }
        }
    }
}
)";


}