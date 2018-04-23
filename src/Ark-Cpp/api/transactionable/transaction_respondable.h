

#ifndef TRANSACTION_RESPONDABLE_H
#define TRANSACTION_RESPONDABLE_H

#include "platform.h"
#include "transaction.h"

#include <array>

namespace ARK {
namespace API {
namespace Transaction {
namespace Respondable  {

/*************************************************
*	  ARK::API::Transaction::Respondable::Unconfirmed
*
*   @param: bool loaded, int now, char blocksCount[64];
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @brief: Model for Loader Status API Response
**************************************************/
class Unconfirmed : public Printable {
  private:
	std::array<ARK::Transaction, 5> transactions_;
    size_t count_;
	

  public:
    Unconfirmed(const ARK::Transaction* const tx, size_t count) : count_(count) {
		if (count_ > transactions_.size()) {
			throw std::runtime_error("Too many transactions");
		}
      for (auto i = 0u; i < count_; ++i)
      {
        this->transactions_[i] = tx[i];
      }
    }

	const std::array<ARK::Transaction, 5>& transactions() const noexcept { return transactions_; }
	size_t count() const noexcept { return count_; }

    /*************************************************
    *	  ARK::API::Transaction::Respondable::Unconfirmed 
    *
    *   @methods:	printTo(HardwareSerial &serial)
    *
    *   @brief: Prints API Transaction Unconfirmed Response to Serial
    **************************************************/
    size_t printTo(Print& p) const override;

};
/*************************************************/

}
}
}
}

#endif