/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include <stdlib.h>
#include <string.h>

#include "lista.h"

SCENARIO("Adiciona elementos ao final de uma lista de inteiros", "[PushBackInt]") {
    GIVEN("Uma lista inicializada.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);

        WHEN ("Adiciono elementos ao final da lista") {
            for (int i = 0; i < 10; i++) {
                Lista_pushBack(&intlist, &i);
            }
            THEN("A lista não está vazia") {
                REQUIRE (false == bool(Lista_isEmpty(&intlist)));
            }
            THEN("A lista tem 10 elementos.") {
                REQUIRE (10 == Lista_size(&intlist));
            }
            Lista_delete(&intlist);
        }

        AND_WHEN ("A lista é destruîda.") {
            for (int i = 0; i < 10; i++) {
                Lista_pushBack(&intlist, &i);
            }
            Lista_delete(&intlist);
            THEN ("A lista está vazia.") {
                REQUIRE (true == bool(Lista_isEmpty(&intlist)));
            }
            AND_THEN("A lista tem 0 elementos.") {
                REQUIRE (0 == Lista_size(&intlist));
            }
        }
    }
}

SCENARIO("Adiciona elementos no início de uma lista de inteiros", "[PushFrontInt]") {
    GIVEN("Uma lista inicializada.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);

        WHEN ("Adiciono elementos no início da lista") {
            for (int i = 0; i < 10; i++) {
                Lista_pushFront(&intlist, &i);
            }
            THEN("A lista não está vazia") {
                REQUIRE (false == bool(Lista_isEmpty(&intlist)));
            }
            THEN("A lista tem 10 elementos.") {
                REQUIRE (10 == Lista_size(&intlist));
            }
            Lista_delete(&intlist);
        }
        AND_WHEN ("A lista é destruîda.") {
            for (int i = 0; i < 10; i++) {
                Lista_pushFront(&intlist, &i);
            }
            Lista_delete(&intlist);
            THEN ("A lista está vazia.") {
                REQUIRE (true == bool(Lista_isEmpty(&intlist)));
            }
            AND_THEN("A lista tem 0 elementos.") {
                REQUIRE (0 == Lista_size(&intlist));
            }
        }
    }
}

SCENARIO("Adiciona elementos ao final de uma lista de double", "[PushBackDouble]") {
    GIVEN("Uma lista inicializada.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);

        WHEN ("Adiciono elementos no início da lista") {
            for (double i = 0; i < 10; i++) {
                Lista_pushBack(&doublelist, &i);
            }
            THEN("A lista não está vazia") {
                REQUIRE (false == bool(Lista_isEmpty(&doublelist)));
            }
            THEN("A lista tem 10 elementos.") {
                REQUIRE (10 == Lista_size(&doublelist));
            }
            Lista_delete(&doublelist);
        }
        WHEN ("A lista é destruîda.") {
            for (double i = 0; i < 10; i++) {
                Lista_pushBack(&doublelist, &i);
            }
            Lista_delete(&doublelist);
            THEN ("A lista está vazia.") {
                REQUIRE (true == bool(Lista_isEmpty(&doublelist)));
            }
            AND_THEN("A lista tem 0 elementos.") {
                REQUIRE (0 == Lista_size(&doublelist));
            }
        }
    }
}

SCENARIO("Adiciona elementos ao final de uma lista de double", "[PushFrontDouble]") {
    GIVEN("Uma lista inicializada.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);

        WHEN ("Adiciono elementos no início da lista") {
            for (double i = 0; i < 10; i++) {
                Lista_pushFront(&doublelist, &i);
            }
            THEN("A lista não está vazia") {
                REQUIRE (false == bool(Lista_isEmpty(&doublelist)));
            }
            THEN("A lista tem 10 elementos.") {
                REQUIRE (10 == Lista_size(&doublelist));
            }
            Lista_delete(&doublelist);
        }
        WHEN ("A lista é destruîda.") {
            for (double i = 0; i < 10; i++) {
                Lista_pushFront(&doublelist, &i);
            }
            Lista_delete(&doublelist);
            THEN ("A lista está vazia.") {
                REQUIRE (true == bool(Lista_isEmpty(&doublelist)));
            }
            AND_THEN("A lista tem 0 elementos.") {
                REQUIRE (0 == Lista_size(&doublelist));
            }
        }
    }
}

/*

SCENARIO("Adiciona elementos ao final de uma lista de strings", "[PushBackString]") {
    GIVEN("Uma lista inicializada.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), free);

        WHEN ("Adiciono elementos ao final da lista") {
            const char *nomes[] = {"a","b","c", "d", "e"};
            for (int i = 0; i < 5; i++) {
                char* value = strdup(nomes[i]);
                Lista_pushBack(&strlist, &value);
            }
            THEN("A lista não está vazia") {
                REQUIRE (false == bool(Lista_isEmpty(&strlist)));
            }
            THEN("A lista tem 5 elementos.") {
                REQUIRE (5 == Lista_size(&strlist));
            }
            Lista_delete(&strlist);
        }
        AND_WHEN ("A lista é destruîda.") {
            const char *nomes[] = {"a","b","c", "d", "e"};
            for (int i = 0; i < 5; i++) {
                char* value = strdup(nomes[i]);
                Lista_pushBack(&strlist, &value);
            }
            Lista_delete(&strlist);
            THEN ("A lista está vazia.") {
                REQUIRE (true == bool(Lista_isEmpty(&strlist)));
            }
            AND_THEN("A lista tem 0 elementos.") {
                REQUIRE (0 == Lista_size(&strlist));
            }
        }
    }
}

SCENARIO("Adiciona elementos ao final de uma lista de strings", "[PushFrontString]") {
    GIVEN("Uma lista inicializada.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), free);

        WHEN ("Adiciono elementos ao final da lista") {
            const char *nomes[] = {"a","b","c", "d", "e"};
            for (int i = 0; i < 5; i++) {
                char* value = strdup(nomes[i]);
                Lista_pushFront(&strlist, &value);
            }

            THEN("A lista não está vazia") {
                REQUIRE (false == bool(Lista_isEmpty(&strlist)));
            }
            THEN("A lista tem 5 elementos.") {
                REQUIRE (5 == Lista_size(&strlist));
            }

            Lista_delete(&strlist);
        }
    }
}

*/
