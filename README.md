# CC342 — DAS Course Website

This site is hosted through GitHub Pages. For routine updates, **do not edit `index.html`**.

## Update announcements

1. Open `announcements.md` in the GitHub repository.
2. Click the pencil (**Edit**) icon.
3. Type your announcement using ordinary text. Use `##` at the beginning of a line for a heading and `-` for bullets. A line containing `---` separates announcements.
4. Click **Commit changes**. Refresh the website after GitHub Pages finishes deployment.

## Update instructor information / office hours

1. Open `instructor.md` in the GitHub repository.
2. Click **Edit**, replace the placeholder information, then **Commit changes**.
3. Public website visitors can see whatever you publish here. Do not publish private phone numbers or other personal information.

## Upload weekly PDFs

1. Open `materials/week01/` (or the relevant week folder) in the repository. If it does not exist, create it by choosing **Add file → Create new file** and typing `materials/week01/README.md`.
2. Choose **Add file → Upload files**, select the PDFs and commit them.
3. Filenames containing `slide` or `presentation` appear under **Lecture Slides**; names containing `note` or `handout` appear under **Detailed Notes**; other PDFs appear under **Additional Materials**.
4. Students see the files after repository/API caching settles. Files must be in the public repository's `main` branch.

**Note:** GitHub Pages does not list files automatically. This website's JavaScript uses GitHub's public API for the weekly PDFs. Markdown info loads directly from your deployed site, so the Markdown files must be uploaded alongside `index.html`.
