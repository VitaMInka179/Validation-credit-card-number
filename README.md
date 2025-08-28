# Validation-credit-card-number
Thise program will allow you check is the credit card number (CCN) is valid (is it can exist) if so -> will show the owner of its
----------
1. The [site](https://developer.paypal.com/api/nvp-soap/payflow/integration-guide/test-transactions/#standard-test-cards) were exist vary of VALID CCN
2. The allowed digits length of CCN: 13; 15; 16
3. The owners which will be displayed: American Express (American Exp.); Mastercard; Visa
   In case of checking the non-provided's CCN program will show "Other" in line of owners
----------
Note: thise program **doesn't** check is the CCN is perconalized, its only check is the CCN **can** be perconalized based on [Luhn's algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm)
      It's fully recommended to run thise program in cs50 [Codespace](https://cs50.dev/) (check video file for help)
