# To clone a remote git repository to a local repository in the local pc:
 cd /h/GitHubLocalRepository
 git clone https://github.com/JariMutikainen/geeksExercises.git

# To update the local copy of the origin/master to be identical to the
# remote origin/master:
 git fetch -t # -t = 'with the tags included'.
# At this point the origin/master in the local repository = origin/master in
# the remote repository.
 git checkout master # Goto the master branch in the local repository
 git log -20 --graph --decorate --oneline master # Show the last 20 commits.
 git log -20 --graph --decorate --oneline origin/master 
# ToinenKokeilussa tehty rivi.
 git merge origin/master # In the local repo merge origin/master into master.

# To start a new development branch named jari/readme from the commit
# that the master-label is pointing at in the local repository:
git checkout -b jari/readme master # -b = 'branch'.

git status
git add --all # To add changes from the working area into the stage
git commit -m "Added new text into the readme.txt file." # -m = 'message'
git status
