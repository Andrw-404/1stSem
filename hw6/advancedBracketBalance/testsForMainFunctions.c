#include "testsForMainFunctions.h"
#include "advancedBracketBalance.h"

#include <stdbool.h>

bool testForHaveBrackets() {
    return !haveBrackets("qwerty") && haveBrackets("qw((erty))") &&
        !haveBrackets("zxczxc") && haveBrackets("zxc]") && haveBrackets("}}dsa") && haveBrackets("(agfd{]");
}

bool testForBalance() {
    return !advancedBracketBalance(")))(((") && !advancedBracketBalance("}}}{{{") && !advancedBracketBalance("]]][[[")
        && advancedBracketBalance("(())") && advancedBracketBalance("{{}}") && advancedBracketBalance("[[]]")
        && !advancedBracketBalance(")dsd))(fds((") && !advancedBracketBalance("a}vc}}{{dsf{s") && !advancedBracketBalance("ytr]gf]][dg[[")
        && advancedBracketBalance("dsa(gdf(fds)dsa)") && advancedBracketBalance("{bc{fhhj}vxs}") && advancedBracketBalance("[eqq[das]]dw");
}