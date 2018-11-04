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
                    "type": "text", 
                    "fields": {
                        "raw": {
                            "type": "keyword", 
                            "ignore_above": 256
                        }
                    }
                }, 
                "pub_keys": {
                    "type": "nested", 
                    "properties": {
                        "key": {
                            "type": "keyword"
                        }, 
                        "permission": {
                            "type": "keyword"
                        }
                    }
                }, 
                "account_controls": {
                    "type": "nested", 
                    "properties": {
                        "name": {
                            "type": "keyword"
                        }, 
                        "permission": {
                            "type": "keyword"
                        }
                    }
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
                "createAt": {
                    "type": "date"
                },
                "updateAt": {
                    "type": "date"
                },
                "block": {
                    "enabled": false
                }
            }
        }
    }
}
)";

static const std::string trans_mapping = R"(
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
                "actions": {
                    "enabled": false
                }
            }
        }
    }
}
)";


static const std::string block_states_mapping = R"(
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
                "block_header_state": {
                    "enabled": false
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
                    "enabled": false
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

static const std::string action_traces_mapping = R"(
{
    "mappings": {
        "_doc": {
            "properties": {
                "trx_id": {
                    "type": "keyword"
                }, 
                "producer_block_id": {
                    "type": "keyword"
                }, 
                "elapsed": {
                    "type": "long"
                }, 
                "context_free": {
                    "type": "boolean"
                }, 
                "console": {
                    "type": "text"
                }, 
                "block_num": {
                    "type": "long"
                }, 
                "block_time": {
                    "type": "date"
                }, 
                "createAt": {
                    "type": "date"
                }, 
                "updateAt": {
                    "type": "date"
                }, 
                "receipt": {
                    "enabled": false
                }, 
                "act": {
                    "properties": {
                        "name": {
                            "type": "keyword"
                        }, 
                        "authorization": {
                            "type": "nested", 
                            "properties": {
                                "actor": {
                                    "type": "keyword"
                                }, 
                                "permission": {
                                    "type": "keyword"
                                }
                            }
                        }, 
                        "account": {
                            "type": "keyword"
                        }, 
                        "hex_data": {
                            "enabled": false
                        }, 
                        "data": {
                            "properties": {
                                "from": {
                                    "type": "keyword"
                                }, 
                                "to": {
                                    "type": "keyword"
                                }, 
                                "quantity": {
                                    "type": "text"
                                }, 
                                "memo": {
                                    "type": "text"
                                }, 
                                "vmtype": {
                                    "type": "keyword"
                                }, 
                                "vmversion": {
                                    "type": "keyword"
                                }, 
                                "code": {
                                    "enabled": false
                                }, 
                                "abi": {
                                    "enabled": false
                                }, 
                                "account": {
                                    "type": "keyword"
                                }
                            }
                        }
                    }
                }, 
                "account_ram_deltas": {
                    "enabled": false
                }
            }
        }
    }
}
)";

}
