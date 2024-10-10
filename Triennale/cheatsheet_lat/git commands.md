branch disponibili
```
$ git branch -a
```

cancellare un branch da remoto
```
$ git push origin --delete nome-branch
```

branch in locale
```
$ git branch
```

rimuovere un branch in locale
```
$ git branch -d nome-branch
```

create a new branch
```
$ git checkout -b my-feature-branch
```


scaricare le modifiche presenti dal main branch remoto
```
$ git fetch origin 
# Downloads new data (commits, branches, tags) from the remote repository **without modifying** your working directory or current branch.

$ git checkout main 
# Or the base branch of the project 

$ git pull origin main
```

merge the branches
```
$ git checkout my-feature-branch 
$ git merge main
```

push the feature branch to github
```
$ git push origin my-feature-branch
```

