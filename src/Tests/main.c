/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Damgard Geisler Kroigard Cryptosystem test file.
 *                      Please read the paper:
 *                      "Efficient and Secure Comparison for Online Auctions" and its 
 *			correction paper. 
 *
 *        Version:  1.0
 *        Created:  12/30/2009 12:03:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Marc X. Makkes (c), _@makkes.mx
 *
 * =====================================================================================
 */
#include "dgk.h"
#include "dgk_keygen.h"
#include "random.h"

int
main ( int argc, char *argv[] )
{
		mpz_t vp, vq , u; 
		mpz_t uvp;
		mpz_t uvq;
		mpz_t p,q;
		mpz_t n; 
		mpz_t r;
		mpz_t rp, rq;
		mpz_t t1, t2, t3, t4;
		mpz_init(vp); mpz_init(vq);
		mpz_init(u);
		mpz_init(uvp); mpz_init(uvq);
		mpz_init(rp); mpz_init(rq);
		mpz_init(r);
		mpz_t g, h;
		mpz_init(p); mpz_init(q);
		mpz_init(t1); mpz_init(t2);
		mpz_init(t3); mpz_init(r);
		mpz_init(g), mpz_init(h);
		mpz_init(n); mpz_init(t4);

		dgk_pub_t *pub = (dgk_pub_t *)malloc(sizeof(dgk_pub_t));
		dgk_priv_t *priv = (dgk_priv_t *)malloc(sizeof(dgk_priv_t));
		
		/*                         k   t    l */
		dgk_gen_keys(priv, pub, 2048, 320, 16 );
	


		gmp_printf("q : %Zd\n", priv->q);
		gmp_printf("p : %Zd\n", priv->p);
		gmp_printf("u : %Zd\n", pub->u);
		gmp_printf("vp: %Zd\n", priv->vp);
		gmp_printf("vq: %Zd\n", priv->vq);
		gmp_printf("g : %Zd\n", pub->g);
		gmp_printf("h : %Zd\n", pub->h);


		mpz_t m, vpq ;
		mpz_t c;
		mpz_init_set_ui(m, 3);
		mpz_init(vpq);
		mpz_init(c);
		
		mpz_mul(vpq, priv->vp, priv->vq);
		dgk_get_random_num(r, 320);

		dgk_encrypt(c, m, pub->g, pub->n, pub->h, r);
		gmp_printf("c %Zd\n", c);
		dgk_decrypt(t1, c, priv->vpq, priv->u, priv->n, priv->rtab);
		gmp_printf("m %Zd\n", t1);

		mpz_powm(t1, pub->g, m, pub->n);
		mpz_powm(t2, pub->h, r, pub->n);
		mpz_mul(t3, t2, t1);
		mpz_mod(t1, t3, pub->n);


		mpz_powm(t4, pub->g, m, pub->n);
		mpz_powm(t2, t4, vpq, priv->n);
		mpz_powm(t2, t1, vpq, priv->n);


		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

