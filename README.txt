# To clone a remote git repository to a local repository in the local pc:
 cd /h/GitHubLocalRepository
 git clone https://github.com/JariMutikainen/geeksExercises.git

# To update the local copy of the origin/master to be identical to the
# remote origin/master:
 git fetch -t # -t = 'with the tags included'.
 git checkout master # Goto the master branch in the local repository
 git log -20 --graph --decorate --oneline master # Show the last 20 commits.
 git log -20 --graph --decorate --oneline origin/master 
# ToinenKokeilussa tehty rivi.
