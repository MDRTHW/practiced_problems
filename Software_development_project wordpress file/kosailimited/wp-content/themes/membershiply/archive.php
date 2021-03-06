<?php
/**
 * The template for displaying archive pages
 *
 * @link https://codex.wordpress.org/Template_Hierarchy
 *
 * @package membershiply
 */

get_header(); ?>

	<div id="primary" class="featured-content content-area <?php if ( get_theme_mod( 'blogfeed_show_sidebar' ) == '1' ) : ?>fullwidth-area-blog <?php else : ?>add-blog-to-sidebar<?php endif; ?>">
		<main id="main" class="site-main all-blog-articles">

		<?php
		if ( have_posts() ) : ?>

			<header class="fbox page-header">
				<?php
					the_archive_title( '<h1 class="page-title">', '</h1>' );
					the_archive_description( '<div class="archive-description">', '</div>' );
				?>
			</header><!-- .page-header -->

			<?php
			/* Start the Loop */
			while ( have_posts() ) : the_post();

				/*
				 * Include the Post-Format-specific template for the content.
				 * If you want to override this in a child theme, then include a file
				 * called content-___.php (where ___ is the Post Format name) and that will be used instead.
				 */
				get_template_part( 'template-parts/content', get_post_format() );

			endwhile;

		echo '<div class="text-center pag-wrapper">';
				membershiply_numeric_posts_nav();
				echo '</div>';
		else :

			get_template_part( 'template-parts/content', 'none' );

		endif; ?>

		</main><!-- #main -->
	</div><!-- #primary -->

<?php if ( get_theme_mod( 'blogfeed_show_sidebar' ) == '1' ) : ?>
	<?php else : ?>
	<?php get_sidebar(); ?>
<?php endif; ?>


<?php
get_footer();
