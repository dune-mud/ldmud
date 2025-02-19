/* We check whether, that - although the struct in tl-private-struct2
 * is private - we can access the members with compile-time lookup.
 */
public inherit "tl-private-struct2-a";

int run_test()
{
    string *instrs;

    if (sv2.member2 != 42)
        return 0;

    instrs = last_instructions(20, 0);
    reverse(&instrs);

    foreach (int i: sizeof(instrs))
    {
        if ("  .  " in instrs[i])
        {
            /* -1 as an argument to index operation
             * would mean runtime lookup.
             */
            return !("  nconst1 " in instrs[i+1]);
        }
    }
    /* Instruction not found? */
    return 0;
}
