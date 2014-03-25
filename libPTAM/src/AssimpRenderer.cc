




<!DOCTYPE html>
<html class="  ">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    
    
    <title>PTAM-GPL/libPTAM/src/AssimpRenderer.cc at master · blefaudeux/PTAM-GPL</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <meta property="fb:app_id" content="1401488693436528"/>

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="blefaudeux/PTAM-GPL" name="twitter:title" /><meta content="PTAM-GPL - PTAM (Parallel Tracking and Mapping) re-released under GPLv3." name="twitter:description" /><meta content="https://avatars2.githubusercontent.com/u/3072861?s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://avatars2.githubusercontent.com/u/3072861?s=400" property="og:image" /><meta content="blefaudeux/PTAM-GPL" property="og:title" /><meta content="https://github.com/blefaudeux/PTAM-GPL" property="og:url" /><meta content="PTAM-GPL - PTAM (Parallel Tracking and Mapping) re-released under GPLv3." property="og:description" />

    <link rel="assets" href="https://github.global.ssl.fastly.net/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035/">
    <link rel="xhr-socket" href="/_sockets" />

    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="614C6E22:75FB:F7F8E1:5331BEC0" name="octolytics-dimension-request_id" /><meta content="3072861" name="octolytics-actor-id" /><meta content="blefaudeux" name="octolytics-actor-login" /><meta content="95129eadec7e451a911117456005505a2166509347848ba2482e6f233d247636" name="octolytics-actor-hash" />
    

    
    
    <link rel="icon" type="image/x-icon" href="https://github.global.ssl.fastly.net/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="tE+izvxnmy3Bhtk+h//vlHT5F7r/fPOzxEtPGy0HZkI=" name="csrf-token" />

    <link href="https://github.global.ssl.fastly.net/assets/github-2714be798e3a1abfcbd49ca563fdfa1c177cd2e9.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://github.global.ssl.fastly.net/assets/github2-11ee1161f68234125b5e8198b6c00e0409587b77.css" media="all" rel="stylesheet" type="text/css" />
    


        <script crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/frameworks-1eb4805d296158ea875ffc5fa959a11f5a3cdf13.js" type="text/javascript"></script>
        <script async="async" crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/github-0eb4075decc9810b544396b3366e14fecf793432.js" type="text/javascript"></script>
        
        
      <meta http-equiv="x-pjax-version" content="ec5d8630b4ee3231236cfa8bf8abbf04">

        <link data-pjax-transient rel='permalink' href='/blefaudeux/PTAM-GPL/blob/3d151f95af628523af8492c4a6eca85d0207540d/libPTAM/src/AssimpRenderer.cc'>

  <meta name="description" content="PTAM-GPL - PTAM (Parallel Tracking and Mapping) re-released under GPLv3." />

  <meta content="3072861" name="octolytics-dimension-user_id" /><meta content="blefaudeux" name="octolytics-dimension-user_login" /><meta content="16832934" name="octolytics-dimension-repository_id" /><meta content="blefaudeux/PTAM-GPL" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="true" name="octolytics-dimension-repository_is_fork" /><meta content="13823564" name="octolytics-dimension-repository_parent_id" /><meta content="Oxford-PTAM/PTAM-GPL" name="octolytics-dimension-repository_parent_nwo" /><meta content="13823564" name="octolytics-dimension-repository_network_root_id" /><meta content="Oxford-PTAM/PTAM-GPL" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/blefaudeux/PTAM-GPL/commits/master.atom" rel="alternate" title="Recent Commits to PTAM-GPL:master" type="application/atom+xml" />

  </head>


  <body class="logged_in  env-production linux vis-public fork page-blob">
    <a href="#start-of-content" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/">
  <span class="mega-octicon octicon-mark-github"></span>
</a>

    
    <a href="/notifications" aria-label="You have no unread notifications" class="notification-indicator tooltipped tooltipped-s" data-gotokey="n">
        <span class="mail-status all-read"></span>
</a>

      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<div class="commandbar">
  <span class="message"></span>
  <input type="text" data-hotkey="/ s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    data-username="blefaudeux"
      data-repo="blefaudeux/PTAM-GPL"
      data-branch="master"
      data-sha="96a2beacb5c6892641e8472b593bbbaa0d83a545"
  >
  <div class="display hidden"></div>
</div>

    <input type="hidden" name="nwo" value="blefaudeux/PTAM-GPL" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target" role="button" aria-haspopup="true">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container" aria-hidden="true">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="help tooltipped tooltipped-s" aria-label="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
        <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="https://help.github.com">Help</a></li>
        </ul>
      </div>

    


  <ul id="user-links">
    <li>
      <a href="/blefaudeux" class="name">
        <img alt="blefaudeux" class=" js-avatar" data-user="3072861" height="20" src="https://avatars1.githubusercontent.com/u/3072861?s=140" width="20" /> blefaudeux
      </a>
    </li>

    <li class="new-menu dropdown-toggle js-menu-container">
      <a href="#" class="js-menu-target tooltipped tooltipped-s" aria-label="Create new...">
        <span class="octicon octicon-plus"></span>
        <span class="dropdown-arrow"></span>
      </a>

      <div class="new-menu-content js-menu-content">
      </div>
    </li>

    <li>
      <a href="/settings/profile" id="account_settings"
        class="tooltipped tooltipped-s"
        aria-label="Account settings ">
        <span class="octicon octicon-tools"></span>
      </a>
    </li>
    <li>
      <a class="tooltipped tooltipped-s" href="/logout" data-method="post" id="logout" aria-label="Sign out">
        <span class="octicon octicon-log-out"></span>
      </a>
    </li>

  </ul>

<div class="js-new-dropdown-contents hidden">
  

<ul class="dropdown-menu">
  <li>
    <a href="/new"><span class="octicon octicon-repo-create"></span> New repository</a>
  </li>
  <li>
    <a href="/organizations/new"><span class="octicon octicon-organization"></span> New organization</a>
  </li>


    <li class="section-title">
      <span title="blefaudeux/PTAM-GPL">This repository</span>
    </li>
      <li>
        <a href="/blefaudeux/PTAM-GPL/settings/collaboration"><span class="octicon octicon-person-add"></span> New collaborator</a>
      </li>
</ul>

</div>


    
  </div>
</div>

      

        



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        

<ul class="pagehead-actions">

    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="tE+izvxnmy3Bhtk+h//vlHT5F7r/fPOzxEtPGy0HZkI=" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="16832934" />

    <div class="select-menu js-menu-container js-select-menu">
      <a class="social-count js-social-count" href="/blefaudeux/PTAM-GPL/watchers">
        1
      </a>
      <span class="minibutton select-menu-button with-count js-menu-target" role="button" tabindex="0" aria-haspopup="true">
        <span class="js-select-button">
          <span class="octicon octicon-eye-unwatch"></span>
          Unwatch
        </span>
      </span>

      <div class="select-menu-modal-holder">
        <div class="select-menu-modal subscription-menu-modal js-menu-content" aria-hidden="true">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="octicon octicon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container" role="menu">

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for conversations in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-watch"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

  <li>
  

  <div class="js-toggler-container js-social-container starring-container ">
    <a href="/blefaudeux/PTAM-GPL/unstar"
      class="minibutton with-count js-toggler-target star-button starred"
      aria-label="Unstar this repository" title="Unstar blefaudeux/PTAM-GPL" data-remote="true" data-method="post" rel="nofollow">
      <span class="octicon octicon-star-delete"></span><span class="text">Unstar</span>
    </a>

    <a href="/blefaudeux/PTAM-GPL/star"
      class="minibutton with-count js-toggler-target star-button unstarred"
      aria-label="Star this repository" title="Star blefaudeux/PTAM-GPL" data-remote="true" data-method="post" rel="nofollow">
      <span class="octicon octicon-star"></span><span class="text">Star</span>
    </a>

      <a class="social-count js-social-count" href="/blefaudeux/PTAM-GPL/stargazers">
        1
      </a>
  </div>

  </li>


        <li>
          <a href="/blefaudeux/PTAM-GPL/fork" class="minibutton with-count js-toggler-target fork-button lighter tooltipped-n" title="Fork your own copy of blefaudeux/PTAM-GPL to your account" aria-label="Fork your own copy of blefaudeux/PTAM-GPL to your account" rel="nofollow" data-method="post">
            <span class="octicon octicon-git-branch-create"></span><span class="text">Fork</span>
          </a>
          <a href="/blefaudeux/PTAM-GPL/network" class="social-count">17</a>
        </li>


</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="repo-label"><span>public</span></span>
          <span class="mega-octicon octicon-repo-forked"></span>
          <span class="author">
            <a href="/blefaudeux" class="url fn" itemprop="url" rel="author"><span itemprop="title">blefaudeux</span></a>
          </span>
          <span class="repohead-name-divider">/</span>
          <strong><a href="/blefaudeux/PTAM-GPL" class="js-current-repository js-repo-home-link">PTAM-GPL</a></strong>

          <span class="page-context-loader">
            <img alt="Octocat-spinner-32" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

            <span class="fork-flag">
              <span class="text">forked from <a href="/Oxford-PTAM/PTAM-GPL">Oxford-PTAM/PTAM-GPL</a></span>
            </span>
        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline js-new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped tooltipped-w" aria-label="Code">
        <a href="/blefaudeux/PTAM-GPL" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-gotokey="c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_tags repo_branches /blefaudeux/PTAM-GPL">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


      <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
        <a href="/blefaudeux/PTAM-GPL/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-gotokey="p" data-selected-links="repo_pulls /blefaudeux/PTAM-GPL/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class='counter'>0</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


        <li class="tooltipped tooltipped-w" aria-label="Wiki">
          <a href="/blefaudeux/PTAM-GPL/wiki" aria-label="Wiki" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_wiki /blefaudeux/PTAM-GPL/wiki">
            <span class="octicon octicon-book"></span> <span class="full-word">Wiki</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>
    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped tooltipped-w" aria-label="Pulse">
        <a href="/blefaudeux/PTAM-GPL/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /blefaudeux/PTAM-GPL/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Graphs">
        <a href="/blefaudeux/PTAM-GPL/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /blefaudeux/PTAM-GPL/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Network">
        <a href="/blefaudeux/PTAM-GPL/network" aria-label="Network" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-selected-links="repo_network /blefaudeux/PTAM-GPL/network">
          <span class="octicon octicon-git-branch"></span> <span class="full-word">Network</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


      <div class="sunken-menu-separator"></div>
      <ul class="sunken-menu-group">
        <li class="tooltipped tooltipped-w" aria-label="Settings">
          <a href="/blefaudeux/PTAM-GPL/settings"
            class="sunken-menu-item" data-pjax aria-label="Settings">
            <span class="octicon octicon-tools"></span> <span class="full-word">Settings</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
          </a>
        </li>
      </ul>
  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=push">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/blefaudeux/PTAM-GPL.git" readonly="readonly">

    <span aria-label="copy to clipboard" class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/blefaudeux/PTAM-GPL.git" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="ssh"
  data-url="/users/set_protocol?protocol_selector=ssh&amp;protocol_type=push">
  <h3><strong>SSH</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="git@github.com:blefaudeux/PTAM-GPL.git" readonly="readonly">

    <span aria-label="copy to clipboard" class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="git@github.com:blefaudeux/PTAM-GPL.git" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=push">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/blefaudeux/PTAM-GPL" readonly="readonly">

    <span aria-label="copy to clipboard" class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/blefaudeux/PTAM-GPL" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>,
      <a href="#" class="js-clone-selector" data-protocol="ssh">SSH</a>,
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <span class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <a href="https://help.github.com/articles/which-remote-url-should-i-use">
    <span class="octicon octicon-question"></span>
    </a>
  </span>
</p>



                <a href="/blefaudeux/PTAM-GPL/archive/master.zip"
                   class="minibutton sidebar-button"
                   aria-label="Download blefaudeux/PTAM-GPL as a zip file"
                   title="Download blefaudeux/PTAM-GPL as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:0d48c6352436e9913d659ceaecb69b30 -->

<p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

<a href="/blefaudeux/PTAM-GPL/find/master" data-pjax data-hotkey="t" class="js-show-file-finder" style="display:none">Show File Finder</a>

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu" >
  <span class="minibutton select-menu-button js-menu-target" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-remove-close js-menu-close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Find or create a branch…" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Find or create a branch…">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/blefaudeux/PTAM-GPL/blob/Linuxmint15/libPTAM/src/AssimpRenderer.cc"
                 data-name="Linuxmint15"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="Linuxmint15">Linuxmint15</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/blefaudeux/PTAM-GPL/blob/load_custom_3d_model/libPTAM/src/AssimpRenderer.cc"
                 data-name="load_custom_3d_model"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="load_custom_3d_model">load_custom_3d_model</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/blefaudeux/PTAM-GPL/blob/master/libPTAM/src/AssimpRenderer.cc"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/blefaudeux/PTAM-GPL/blob/unified_build/libPTAM/src/AssimpRenderer.cc"
                 data-name="unified_build"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="unified_build">unified_build</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <form accept-charset="UTF-8" action="/blefaudeux/PTAM-GPL/branches" class="js-create-branch select-menu-item select-menu-new-item-form js-navigation-item js-new-item-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="tE+izvxnmy3Bhtk+h//vlHT5F7r/fPOzxEtPGy0HZkI=" /></div>
            <span class="octicon octicon-git-branch-create select-menu-item-icon"></span>
            <div class="select-menu-item-text">
              <h4>Create branch: <span class="js-new-item-name"></span></h4>
              <span class="description">from ‘master’</span>
            </div>
            <input type="hidden" name="name" id="name" class="js-new-item-value">
            <input type="hidden" name="branch" id="branch" value="master" />
            <input type="hidden" name="path" id="path" value="libPTAM/src/AssimpRenderer.cc" />
          </form> <!-- /.select-menu-item -->

      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/blefaudeux/PTAM-GPL" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">PTAM-GPL</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/blefaudeux/PTAM-GPL/tree/master/libPTAM" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">libPTAM</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/blefaudeux/PTAM-GPL/tree/master/libPTAM/src" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">src</span></a></span><span class="separator"> / </span><strong class="final-path">AssimpRenderer.cc</strong> <span aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="libPTAM/src/AssimpRenderer.cc" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


  <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/blefaudeux/PTAM-GPL/contributors/master/libPTAM/src/AssimpRenderer.cc">
    Fetching contributors…

    <div class="participation">
      <p class="loader-loading"><img alt="Octocat-spinner-32-eaf2f5" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32-EAF2F5.gif" width="16" /></p>
      <p class="loader-error">Cannot retrieve contributors at this time</p>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
        <span class="icon"><b class="octicon octicon-file-text"></b></span>
        <span class="mode" title="File Mode">file</span>
        <span class="meta-divider"></span>
          <span>874 lines (697 sloc)</span>
          <span class="meta-divider"></span>
        <span>25.411 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
                <a class="minibutton js-update-url-with-hash"
                   href="/blefaudeux/PTAM-GPL/edit/master/libPTAM/src/AssimpRenderer.cc"
                   data-method="post" rel="nofollow" data-hotkey="e">Edit</a>
          <a href="/blefaudeux/PTAM-GPL/raw/master/libPTAM/src/AssimpRenderer.cc" class="button minibutton " id="raw-url">Raw</a>
            <a href="/blefaudeux/PTAM-GPL/blame/master/libPTAM/src/AssimpRenderer.cc" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/blefaudeux/PTAM-GPL/commits/master/libPTAM/src/AssimpRenderer.cc" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->

            <a class="minibutton danger empty-icon"
               href="/blefaudeux/PTAM-GPL/delete/master/libPTAM/src/AssimpRenderer.cc"
               data-method="post" data-test-id="delete-blob-file" rel="nofollow">

          Delete
        </a>
      </div><!-- /.actions -->
    </div>
        <div class="blob-wrapper data type-c js-blob-data">
        <table class="file-code file-diff tab-size-8">
          <tr class="file-code-line">
            <td class="blob-line-nums">
              <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
<span id="L156" rel="#L156">156</span>
<span id="L157" rel="#L157">157</span>
<span id="L158" rel="#L158">158</span>
<span id="L159" rel="#L159">159</span>
<span id="L160" rel="#L160">160</span>
<span id="L161" rel="#L161">161</span>
<span id="L162" rel="#L162">162</span>
<span id="L163" rel="#L163">163</span>
<span id="L164" rel="#L164">164</span>
<span id="L165" rel="#L165">165</span>
<span id="L166" rel="#L166">166</span>
<span id="L167" rel="#L167">167</span>
<span id="L168" rel="#L168">168</span>
<span id="L169" rel="#L169">169</span>
<span id="L170" rel="#L170">170</span>
<span id="L171" rel="#L171">171</span>
<span id="L172" rel="#L172">172</span>
<span id="L173" rel="#L173">173</span>
<span id="L174" rel="#L174">174</span>
<span id="L175" rel="#L175">175</span>
<span id="L176" rel="#L176">176</span>
<span id="L177" rel="#L177">177</span>
<span id="L178" rel="#L178">178</span>
<span id="L179" rel="#L179">179</span>
<span id="L180" rel="#L180">180</span>
<span id="L181" rel="#L181">181</span>
<span id="L182" rel="#L182">182</span>
<span id="L183" rel="#L183">183</span>
<span id="L184" rel="#L184">184</span>
<span id="L185" rel="#L185">185</span>
<span id="L186" rel="#L186">186</span>
<span id="L187" rel="#L187">187</span>
<span id="L188" rel="#L188">188</span>
<span id="L189" rel="#L189">189</span>
<span id="L190" rel="#L190">190</span>
<span id="L191" rel="#L191">191</span>
<span id="L192" rel="#L192">192</span>
<span id="L193" rel="#L193">193</span>
<span id="L194" rel="#L194">194</span>
<span id="L195" rel="#L195">195</span>
<span id="L196" rel="#L196">196</span>
<span id="L197" rel="#L197">197</span>
<span id="L198" rel="#L198">198</span>
<span id="L199" rel="#L199">199</span>
<span id="L200" rel="#L200">200</span>
<span id="L201" rel="#L201">201</span>
<span id="L202" rel="#L202">202</span>
<span id="L203" rel="#L203">203</span>
<span id="L204" rel="#L204">204</span>
<span id="L205" rel="#L205">205</span>
<span id="L206" rel="#L206">206</span>
<span id="L207" rel="#L207">207</span>
<span id="L208" rel="#L208">208</span>
<span id="L209" rel="#L209">209</span>
<span id="L210" rel="#L210">210</span>
<span id="L211" rel="#L211">211</span>
<span id="L212" rel="#L212">212</span>
<span id="L213" rel="#L213">213</span>
<span id="L214" rel="#L214">214</span>
<span id="L215" rel="#L215">215</span>
<span id="L216" rel="#L216">216</span>
<span id="L217" rel="#L217">217</span>
<span id="L218" rel="#L218">218</span>
<span id="L219" rel="#L219">219</span>
<span id="L220" rel="#L220">220</span>
<span id="L221" rel="#L221">221</span>
<span id="L222" rel="#L222">222</span>
<span id="L223" rel="#L223">223</span>
<span id="L224" rel="#L224">224</span>
<span id="L225" rel="#L225">225</span>
<span id="L226" rel="#L226">226</span>
<span id="L227" rel="#L227">227</span>
<span id="L228" rel="#L228">228</span>
<span id="L229" rel="#L229">229</span>
<span id="L230" rel="#L230">230</span>
<span id="L231" rel="#L231">231</span>
<span id="L232" rel="#L232">232</span>
<span id="L233" rel="#L233">233</span>
<span id="L234" rel="#L234">234</span>
<span id="L235" rel="#L235">235</span>
<span id="L236" rel="#L236">236</span>
<span id="L237" rel="#L237">237</span>
<span id="L238" rel="#L238">238</span>
<span id="L239" rel="#L239">239</span>
<span id="L240" rel="#L240">240</span>
<span id="L241" rel="#L241">241</span>
<span id="L242" rel="#L242">242</span>
<span id="L243" rel="#L243">243</span>
<span id="L244" rel="#L244">244</span>
<span id="L245" rel="#L245">245</span>
<span id="L246" rel="#L246">246</span>
<span id="L247" rel="#L247">247</span>
<span id="L248" rel="#L248">248</span>
<span id="L249" rel="#L249">249</span>
<span id="L250" rel="#L250">250</span>
<span id="L251" rel="#L251">251</span>
<span id="L252" rel="#L252">252</span>
<span id="L253" rel="#L253">253</span>
<span id="L254" rel="#L254">254</span>
<span id="L255" rel="#L255">255</span>
<span id="L256" rel="#L256">256</span>
<span id="L257" rel="#L257">257</span>
<span id="L258" rel="#L258">258</span>
<span id="L259" rel="#L259">259</span>
<span id="L260" rel="#L260">260</span>
<span id="L261" rel="#L261">261</span>
<span id="L262" rel="#L262">262</span>
<span id="L263" rel="#L263">263</span>
<span id="L264" rel="#L264">264</span>
<span id="L265" rel="#L265">265</span>
<span id="L266" rel="#L266">266</span>
<span id="L267" rel="#L267">267</span>
<span id="L268" rel="#L268">268</span>
<span id="L269" rel="#L269">269</span>
<span id="L270" rel="#L270">270</span>
<span id="L271" rel="#L271">271</span>
<span id="L272" rel="#L272">272</span>
<span id="L273" rel="#L273">273</span>
<span id="L274" rel="#L274">274</span>
<span id="L275" rel="#L275">275</span>
<span id="L276" rel="#L276">276</span>
<span id="L277" rel="#L277">277</span>
<span id="L278" rel="#L278">278</span>
<span id="L279" rel="#L279">279</span>
<span id="L280" rel="#L280">280</span>
<span id="L281" rel="#L281">281</span>
<span id="L282" rel="#L282">282</span>
<span id="L283" rel="#L283">283</span>
<span id="L284" rel="#L284">284</span>
<span id="L285" rel="#L285">285</span>
<span id="L286" rel="#L286">286</span>
<span id="L287" rel="#L287">287</span>
<span id="L288" rel="#L288">288</span>
<span id="L289" rel="#L289">289</span>
<span id="L290" rel="#L290">290</span>
<span id="L291" rel="#L291">291</span>
<span id="L292" rel="#L292">292</span>
<span id="L293" rel="#L293">293</span>
<span id="L294" rel="#L294">294</span>
<span id="L295" rel="#L295">295</span>
<span id="L296" rel="#L296">296</span>
<span id="L297" rel="#L297">297</span>
<span id="L298" rel="#L298">298</span>
<span id="L299" rel="#L299">299</span>
<span id="L300" rel="#L300">300</span>
<span id="L301" rel="#L301">301</span>
<span id="L302" rel="#L302">302</span>
<span id="L303" rel="#L303">303</span>
<span id="L304" rel="#L304">304</span>
<span id="L305" rel="#L305">305</span>
<span id="L306" rel="#L306">306</span>
<span id="L307" rel="#L307">307</span>
<span id="L308" rel="#L308">308</span>
<span id="L309" rel="#L309">309</span>
<span id="L310" rel="#L310">310</span>
<span id="L311" rel="#L311">311</span>
<span id="L312" rel="#L312">312</span>
<span id="L313" rel="#L313">313</span>
<span id="L314" rel="#L314">314</span>
<span id="L315" rel="#L315">315</span>
<span id="L316" rel="#L316">316</span>
<span id="L317" rel="#L317">317</span>
<span id="L318" rel="#L318">318</span>
<span id="L319" rel="#L319">319</span>
<span id="L320" rel="#L320">320</span>
<span id="L321" rel="#L321">321</span>
<span id="L322" rel="#L322">322</span>
<span id="L323" rel="#L323">323</span>
<span id="L324" rel="#L324">324</span>
<span id="L325" rel="#L325">325</span>
<span id="L326" rel="#L326">326</span>
<span id="L327" rel="#L327">327</span>
<span id="L328" rel="#L328">328</span>
<span id="L329" rel="#L329">329</span>
<span id="L330" rel="#L330">330</span>
<span id="L331" rel="#L331">331</span>
<span id="L332" rel="#L332">332</span>
<span id="L333" rel="#L333">333</span>
<span id="L334" rel="#L334">334</span>
<span id="L335" rel="#L335">335</span>
<span id="L336" rel="#L336">336</span>
<span id="L337" rel="#L337">337</span>
<span id="L338" rel="#L338">338</span>
<span id="L339" rel="#L339">339</span>
<span id="L340" rel="#L340">340</span>
<span id="L341" rel="#L341">341</span>
<span id="L342" rel="#L342">342</span>
<span id="L343" rel="#L343">343</span>
<span id="L344" rel="#L344">344</span>
<span id="L345" rel="#L345">345</span>
<span id="L346" rel="#L346">346</span>
<span id="L347" rel="#L347">347</span>
<span id="L348" rel="#L348">348</span>
<span id="L349" rel="#L349">349</span>
<span id="L350" rel="#L350">350</span>
<span id="L351" rel="#L351">351</span>
<span id="L352" rel="#L352">352</span>
<span id="L353" rel="#L353">353</span>
<span id="L354" rel="#L354">354</span>
<span id="L355" rel="#L355">355</span>
<span id="L356" rel="#L356">356</span>
<span id="L357" rel="#L357">357</span>
<span id="L358" rel="#L358">358</span>
<span id="L359" rel="#L359">359</span>
<span id="L360" rel="#L360">360</span>
<span id="L361" rel="#L361">361</span>
<span id="L362" rel="#L362">362</span>
<span id="L363" rel="#L363">363</span>
<span id="L364" rel="#L364">364</span>
<span id="L365" rel="#L365">365</span>
<span id="L366" rel="#L366">366</span>
<span id="L367" rel="#L367">367</span>
<span id="L368" rel="#L368">368</span>
<span id="L369" rel="#L369">369</span>
<span id="L370" rel="#L370">370</span>
<span id="L371" rel="#L371">371</span>
<span id="L372" rel="#L372">372</span>
<span id="L373" rel="#L373">373</span>
<span id="L374" rel="#L374">374</span>
<span id="L375" rel="#L375">375</span>
<span id="L376" rel="#L376">376</span>
<span id="L377" rel="#L377">377</span>
<span id="L378" rel="#L378">378</span>
<span id="L379" rel="#L379">379</span>
<span id="L380" rel="#L380">380</span>
<span id="L381" rel="#L381">381</span>
<span id="L382" rel="#L382">382</span>
<span id="L383" rel="#L383">383</span>
<span id="L384" rel="#L384">384</span>
<span id="L385" rel="#L385">385</span>
<span id="L386" rel="#L386">386</span>
<span id="L387" rel="#L387">387</span>
<span id="L388" rel="#L388">388</span>
<span id="L389" rel="#L389">389</span>
<span id="L390" rel="#L390">390</span>
<span id="L391" rel="#L391">391</span>
<span id="L392" rel="#L392">392</span>
<span id="L393" rel="#L393">393</span>
<span id="L394" rel="#L394">394</span>
<span id="L395" rel="#L395">395</span>
<span id="L396" rel="#L396">396</span>
<span id="L397" rel="#L397">397</span>
<span id="L398" rel="#L398">398</span>
<span id="L399" rel="#L399">399</span>
<span id="L400" rel="#L400">400</span>
<span id="L401" rel="#L401">401</span>
<span id="L402" rel="#L402">402</span>
<span id="L403" rel="#L403">403</span>
<span id="L404" rel="#L404">404</span>
<span id="L405" rel="#L405">405</span>
<span id="L406" rel="#L406">406</span>
<span id="L407" rel="#L407">407</span>
<span id="L408" rel="#L408">408</span>
<span id="L409" rel="#L409">409</span>
<span id="L410" rel="#L410">410</span>
<span id="L411" rel="#L411">411</span>
<span id="L412" rel="#L412">412</span>
<span id="L413" rel="#L413">413</span>
<span id="L414" rel="#L414">414</span>
<span id="L415" rel="#L415">415</span>
<span id="L416" rel="#L416">416</span>
<span id="L417" rel="#L417">417</span>
<span id="L418" rel="#L418">418</span>
<span id="L419" rel="#L419">419</span>
<span id="L420" rel="#L420">420</span>
<span id="L421" rel="#L421">421</span>
<span id="L422" rel="#L422">422</span>
<span id="L423" rel="#L423">423</span>
<span id="L424" rel="#L424">424</span>
<span id="L425" rel="#L425">425</span>
<span id="L426" rel="#L426">426</span>
<span id="L427" rel="#L427">427</span>
<span id="L428" rel="#L428">428</span>
<span id="L429" rel="#L429">429</span>
<span id="L430" rel="#L430">430</span>
<span id="L431" rel="#L431">431</span>
<span id="L432" rel="#L432">432</span>
<span id="L433" rel="#L433">433</span>
<span id="L434" rel="#L434">434</span>
<span id="L435" rel="#L435">435</span>
<span id="L436" rel="#L436">436</span>
<span id="L437" rel="#L437">437</span>
<span id="L438" rel="#L438">438</span>
<span id="L439" rel="#L439">439</span>
<span id="L440" rel="#L440">440</span>
<span id="L441" rel="#L441">441</span>
<span id="L442" rel="#L442">442</span>
<span id="L443" rel="#L443">443</span>
<span id="L444" rel="#L444">444</span>
<span id="L445" rel="#L445">445</span>
<span id="L446" rel="#L446">446</span>
<span id="L447" rel="#L447">447</span>
<span id="L448" rel="#L448">448</span>
<span id="L449" rel="#L449">449</span>
<span id="L450" rel="#L450">450</span>
<span id="L451" rel="#L451">451</span>
<span id="L452" rel="#L452">452</span>
<span id="L453" rel="#L453">453</span>
<span id="L454" rel="#L454">454</span>
<span id="L455" rel="#L455">455</span>
<span id="L456" rel="#L456">456</span>
<span id="L457" rel="#L457">457</span>
<span id="L458" rel="#L458">458</span>
<span id="L459" rel="#L459">459</span>
<span id="L460" rel="#L460">460</span>
<span id="L461" rel="#L461">461</span>
<span id="L462" rel="#L462">462</span>
<span id="L463" rel="#L463">463</span>
<span id="L464" rel="#L464">464</span>
<span id="L465" rel="#L465">465</span>
<span id="L466" rel="#L466">466</span>
<span id="L467" rel="#L467">467</span>
<span id="L468" rel="#L468">468</span>
<span id="L469" rel="#L469">469</span>
<span id="L470" rel="#L470">470</span>
<span id="L471" rel="#L471">471</span>
<span id="L472" rel="#L472">472</span>
<span id="L473" rel="#L473">473</span>
<span id="L474" rel="#L474">474</span>
<span id="L475" rel="#L475">475</span>
<span id="L476" rel="#L476">476</span>
<span id="L477" rel="#L477">477</span>
<span id="L478" rel="#L478">478</span>
<span id="L479" rel="#L479">479</span>
<span id="L480" rel="#L480">480</span>
<span id="L481" rel="#L481">481</span>
<span id="L482" rel="#L482">482</span>
<span id="L483" rel="#L483">483</span>
<span id="L484" rel="#L484">484</span>
<span id="L485" rel="#L485">485</span>
<span id="L486" rel="#L486">486</span>
<span id="L487" rel="#L487">487</span>
<span id="L488" rel="#L488">488</span>
<span id="L489" rel="#L489">489</span>
<span id="L490" rel="#L490">490</span>
<span id="L491" rel="#L491">491</span>
<span id="L492" rel="#L492">492</span>
<span id="L493" rel="#L493">493</span>
<span id="L494" rel="#L494">494</span>
<span id="L495" rel="#L495">495</span>
<span id="L496" rel="#L496">496</span>
<span id="L497" rel="#L497">497</span>
<span id="L498" rel="#L498">498</span>
<span id="L499" rel="#L499">499</span>
<span id="L500" rel="#L500">500</span>
<span id="L501" rel="#L501">501</span>
<span id="L502" rel="#L502">502</span>
<span id="L503" rel="#L503">503</span>
<span id="L504" rel="#L504">504</span>
<span id="L505" rel="#L505">505</span>
<span id="L506" rel="#L506">506</span>
<span id="L507" rel="#L507">507</span>
<span id="L508" rel="#L508">508</span>
<span id="L509" rel="#L509">509</span>
<span id="L510" rel="#L510">510</span>
<span id="L511" rel="#L511">511</span>
<span id="L512" rel="#L512">512</span>
<span id="L513" rel="#L513">513</span>
<span id="L514" rel="#L514">514</span>
<span id="L515" rel="#L515">515</span>
<span id="L516" rel="#L516">516</span>
<span id="L517" rel="#L517">517</span>
<span id="L518" rel="#L518">518</span>
<span id="L519" rel="#L519">519</span>
<span id="L520" rel="#L520">520</span>
<span id="L521" rel="#L521">521</span>
<span id="L522" rel="#L522">522</span>
<span id="L523" rel="#L523">523</span>
<span id="L524" rel="#L524">524</span>
<span id="L525" rel="#L525">525</span>
<span id="L526" rel="#L526">526</span>
<span id="L527" rel="#L527">527</span>
<span id="L528" rel="#L528">528</span>
<span id="L529" rel="#L529">529</span>
<span id="L530" rel="#L530">530</span>
<span id="L531" rel="#L531">531</span>
<span id="L532" rel="#L532">532</span>
<span id="L533" rel="#L533">533</span>
<span id="L534" rel="#L534">534</span>
<span id="L535" rel="#L535">535</span>
<span id="L536" rel="#L536">536</span>
<span id="L537" rel="#L537">537</span>
<span id="L538" rel="#L538">538</span>
<span id="L539" rel="#L539">539</span>
<span id="L540" rel="#L540">540</span>
<span id="L541" rel="#L541">541</span>
<span id="L542" rel="#L542">542</span>
<span id="L543" rel="#L543">543</span>
<span id="L544" rel="#L544">544</span>
<span id="L545" rel="#L545">545</span>
<span id="L546" rel="#L546">546</span>
<span id="L547" rel="#L547">547</span>
<span id="L548" rel="#L548">548</span>
<span id="L549" rel="#L549">549</span>
<span id="L550" rel="#L550">550</span>
<span id="L551" rel="#L551">551</span>
<span id="L552" rel="#L552">552</span>
<span id="L553" rel="#L553">553</span>
<span id="L554" rel="#L554">554</span>
<span id="L555" rel="#L555">555</span>
<span id="L556" rel="#L556">556</span>
<span id="L557" rel="#L557">557</span>
<span id="L558" rel="#L558">558</span>
<span id="L559" rel="#L559">559</span>
<span id="L560" rel="#L560">560</span>
<span id="L561" rel="#L561">561</span>
<span id="L562" rel="#L562">562</span>
<span id="L563" rel="#L563">563</span>
<span id="L564" rel="#L564">564</span>
<span id="L565" rel="#L565">565</span>
<span id="L566" rel="#L566">566</span>
<span id="L567" rel="#L567">567</span>
<span id="L568" rel="#L568">568</span>
<span id="L569" rel="#L569">569</span>
<span id="L570" rel="#L570">570</span>
<span id="L571" rel="#L571">571</span>
<span id="L572" rel="#L572">572</span>
<span id="L573" rel="#L573">573</span>
<span id="L574" rel="#L574">574</span>
<span id="L575" rel="#L575">575</span>
<span id="L576" rel="#L576">576</span>
<span id="L577" rel="#L577">577</span>
<span id="L578" rel="#L578">578</span>
<span id="L579" rel="#L579">579</span>
<span id="L580" rel="#L580">580</span>
<span id="L581" rel="#L581">581</span>
<span id="L582" rel="#L582">582</span>
<span id="L583" rel="#L583">583</span>
<span id="L584" rel="#L584">584</span>
<span id="L585" rel="#L585">585</span>
<span id="L586" rel="#L586">586</span>
<span id="L587" rel="#L587">587</span>
<span id="L588" rel="#L588">588</span>
<span id="L589" rel="#L589">589</span>
<span id="L590" rel="#L590">590</span>
<span id="L591" rel="#L591">591</span>
<span id="L592" rel="#L592">592</span>
<span id="L593" rel="#L593">593</span>
<span id="L594" rel="#L594">594</span>
<span id="L595" rel="#L595">595</span>
<span id="L596" rel="#L596">596</span>
<span id="L597" rel="#L597">597</span>
<span id="L598" rel="#L598">598</span>
<span id="L599" rel="#L599">599</span>
<span id="L600" rel="#L600">600</span>
<span id="L601" rel="#L601">601</span>
<span id="L602" rel="#L602">602</span>
<span id="L603" rel="#L603">603</span>
<span id="L604" rel="#L604">604</span>
<span id="L605" rel="#L605">605</span>
<span id="L606" rel="#L606">606</span>
<span id="L607" rel="#L607">607</span>
<span id="L608" rel="#L608">608</span>
<span id="L609" rel="#L609">609</span>
<span id="L610" rel="#L610">610</span>
<span id="L611" rel="#L611">611</span>
<span id="L612" rel="#L612">612</span>
<span id="L613" rel="#L613">613</span>
<span id="L614" rel="#L614">614</span>
<span id="L615" rel="#L615">615</span>
<span id="L616" rel="#L616">616</span>
<span id="L617" rel="#L617">617</span>
<span id="L618" rel="#L618">618</span>
<span id="L619" rel="#L619">619</span>
<span id="L620" rel="#L620">620</span>
<span id="L621" rel="#L621">621</span>
<span id="L622" rel="#L622">622</span>
<span id="L623" rel="#L623">623</span>
<span id="L624" rel="#L624">624</span>
<span id="L625" rel="#L625">625</span>
<span id="L626" rel="#L626">626</span>
<span id="L627" rel="#L627">627</span>
<span id="L628" rel="#L628">628</span>
<span id="L629" rel="#L629">629</span>
<span id="L630" rel="#L630">630</span>
<span id="L631" rel="#L631">631</span>
<span id="L632" rel="#L632">632</span>
<span id="L633" rel="#L633">633</span>
<span id="L634" rel="#L634">634</span>
<span id="L635" rel="#L635">635</span>
<span id="L636" rel="#L636">636</span>
<span id="L637" rel="#L637">637</span>
<span id="L638" rel="#L638">638</span>
<span id="L639" rel="#L639">639</span>
<span id="L640" rel="#L640">640</span>
<span id="L641" rel="#L641">641</span>
<span id="L642" rel="#L642">642</span>
<span id="L643" rel="#L643">643</span>
<span id="L644" rel="#L644">644</span>
<span id="L645" rel="#L645">645</span>
<span id="L646" rel="#L646">646</span>
<span id="L647" rel="#L647">647</span>
<span id="L648" rel="#L648">648</span>
<span id="L649" rel="#L649">649</span>
<span id="L650" rel="#L650">650</span>
<span id="L651" rel="#L651">651</span>
<span id="L652" rel="#L652">652</span>
<span id="L653" rel="#L653">653</span>
<span id="L654" rel="#L654">654</span>
<span id="L655" rel="#L655">655</span>
<span id="L656" rel="#L656">656</span>
<span id="L657" rel="#L657">657</span>
<span id="L658" rel="#L658">658</span>
<span id="L659" rel="#L659">659</span>
<span id="L660" rel="#L660">660</span>
<span id="L661" rel="#L661">661</span>
<span id="L662" rel="#L662">662</span>
<span id="L663" rel="#L663">663</span>
<span id="L664" rel="#L664">664</span>
<span id="L665" rel="#L665">665</span>
<span id="L666" rel="#L666">666</span>
<span id="L667" rel="#L667">667</span>
<span id="L668" rel="#L668">668</span>
<span id="L669" rel="#L669">669</span>
<span id="L670" rel="#L670">670</span>
<span id="L671" rel="#L671">671</span>
<span id="L672" rel="#L672">672</span>
<span id="L673" rel="#L673">673</span>
<span id="L674" rel="#L674">674</span>
<span id="L675" rel="#L675">675</span>
<span id="L676" rel="#L676">676</span>
<span id="L677" rel="#L677">677</span>
<span id="L678" rel="#L678">678</span>
<span id="L679" rel="#L679">679</span>
<span id="L680" rel="#L680">680</span>
<span id="L681" rel="#L681">681</span>
<span id="L682" rel="#L682">682</span>
<span id="L683" rel="#L683">683</span>
<span id="L684" rel="#L684">684</span>
<span id="L685" rel="#L685">685</span>
<span id="L686" rel="#L686">686</span>
<span id="L687" rel="#L687">687</span>
<span id="L688" rel="#L688">688</span>
<span id="L689" rel="#L689">689</span>
<span id="L690" rel="#L690">690</span>
<span id="L691" rel="#L691">691</span>
<span id="L692" rel="#L692">692</span>
<span id="L693" rel="#L693">693</span>
<span id="L694" rel="#L694">694</span>
<span id="L695" rel="#L695">695</span>
<span id="L696" rel="#L696">696</span>
<span id="L697" rel="#L697">697</span>
<span id="L698" rel="#L698">698</span>
<span id="L699" rel="#L699">699</span>
<span id="L700" rel="#L700">700</span>
<span id="L701" rel="#L701">701</span>
<span id="L702" rel="#L702">702</span>
<span id="L703" rel="#L703">703</span>
<span id="L704" rel="#L704">704</span>
<span id="L705" rel="#L705">705</span>
<span id="L706" rel="#L706">706</span>
<span id="L707" rel="#L707">707</span>
<span id="L708" rel="#L708">708</span>
<span id="L709" rel="#L709">709</span>
<span id="L710" rel="#L710">710</span>
<span id="L711" rel="#L711">711</span>
<span id="L712" rel="#L712">712</span>
<span id="L713" rel="#L713">713</span>
<span id="L714" rel="#L714">714</span>
<span id="L715" rel="#L715">715</span>
<span id="L716" rel="#L716">716</span>
<span id="L717" rel="#L717">717</span>
<span id="L718" rel="#L718">718</span>
<span id="L719" rel="#L719">719</span>
<span id="L720" rel="#L720">720</span>
<span id="L721" rel="#L721">721</span>
<span id="L722" rel="#L722">722</span>
<span id="L723" rel="#L723">723</span>
<span id="L724" rel="#L724">724</span>
<span id="L725" rel="#L725">725</span>
<span id="L726" rel="#L726">726</span>
<span id="L727" rel="#L727">727</span>
<span id="L728" rel="#L728">728</span>
<span id="L729" rel="#L729">729</span>
<span id="L730" rel="#L730">730</span>
<span id="L731" rel="#L731">731</span>
<span id="L732" rel="#L732">732</span>
<span id="L733" rel="#L733">733</span>
<span id="L734" rel="#L734">734</span>
<span id="L735" rel="#L735">735</span>
<span id="L736" rel="#L736">736</span>
<span id="L737" rel="#L737">737</span>
<span id="L738" rel="#L738">738</span>
<span id="L739" rel="#L739">739</span>
<span id="L740" rel="#L740">740</span>
<span id="L741" rel="#L741">741</span>
<span id="L742" rel="#L742">742</span>
<span id="L743" rel="#L743">743</span>
<span id="L744" rel="#L744">744</span>
<span id="L745" rel="#L745">745</span>
<span id="L746" rel="#L746">746</span>
<span id="L747" rel="#L747">747</span>
<span id="L748" rel="#L748">748</span>
<span id="L749" rel="#L749">749</span>
<span id="L750" rel="#L750">750</span>
<span id="L751" rel="#L751">751</span>
<span id="L752" rel="#L752">752</span>
<span id="L753" rel="#L753">753</span>
<span id="L754" rel="#L754">754</span>
<span id="L755" rel="#L755">755</span>
<span id="L756" rel="#L756">756</span>
<span id="L757" rel="#L757">757</span>
<span id="L758" rel="#L758">758</span>
<span id="L759" rel="#L759">759</span>
<span id="L760" rel="#L760">760</span>
<span id="L761" rel="#L761">761</span>
<span id="L762" rel="#L762">762</span>
<span id="L763" rel="#L763">763</span>
<span id="L764" rel="#L764">764</span>
<span id="L765" rel="#L765">765</span>
<span id="L766" rel="#L766">766</span>
<span id="L767" rel="#L767">767</span>
<span id="L768" rel="#L768">768</span>
<span id="L769" rel="#L769">769</span>
<span id="L770" rel="#L770">770</span>
<span id="L771" rel="#L771">771</span>
<span id="L772" rel="#L772">772</span>
<span id="L773" rel="#L773">773</span>
<span id="L774" rel="#L774">774</span>
<span id="L775" rel="#L775">775</span>
<span id="L776" rel="#L776">776</span>
<span id="L777" rel="#L777">777</span>
<span id="L778" rel="#L778">778</span>
<span id="L779" rel="#L779">779</span>
<span id="L780" rel="#L780">780</span>
<span id="L781" rel="#L781">781</span>
<span id="L782" rel="#L782">782</span>
<span id="L783" rel="#L783">783</span>
<span id="L784" rel="#L784">784</span>
<span id="L785" rel="#L785">785</span>
<span id="L786" rel="#L786">786</span>
<span id="L787" rel="#L787">787</span>
<span id="L788" rel="#L788">788</span>
<span id="L789" rel="#L789">789</span>
<span id="L790" rel="#L790">790</span>
<span id="L791" rel="#L791">791</span>
<span id="L792" rel="#L792">792</span>
<span id="L793" rel="#L793">793</span>
<span id="L794" rel="#L794">794</span>
<span id="L795" rel="#L795">795</span>
<span id="L796" rel="#L796">796</span>
<span id="L797" rel="#L797">797</span>
<span id="L798" rel="#L798">798</span>
<span id="L799" rel="#L799">799</span>
<span id="L800" rel="#L800">800</span>
<span id="L801" rel="#L801">801</span>
<span id="L802" rel="#L802">802</span>
<span id="L803" rel="#L803">803</span>
<span id="L804" rel="#L804">804</span>
<span id="L805" rel="#L805">805</span>
<span id="L806" rel="#L806">806</span>
<span id="L807" rel="#L807">807</span>
<span id="L808" rel="#L808">808</span>
<span id="L809" rel="#L809">809</span>
<span id="L810" rel="#L810">810</span>
<span id="L811" rel="#L811">811</span>
<span id="L812" rel="#L812">812</span>
<span id="L813" rel="#L813">813</span>
<span id="L814" rel="#L814">814</span>
<span id="L815" rel="#L815">815</span>
<span id="L816" rel="#L816">816</span>
<span id="L817" rel="#L817">817</span>
<span id="L818" rel="#L818">818</span>
<span id="L819" rel="#L819">819</span>
<span id="L820" rel="#L820">820</span>
<span id="L821" rel="#L821">821</span>
<span id="L822" rel="#L822">822</span>
<span id="L823" rel="#L823">823</span>
<span id="L824" rel="#L824">824</span>
<span id="L825" rel="#L825">825</span>
<span id="L826" rel="#L826">826</span>
<span id="L827" rel="#L827">827</span>
<span id="L828" rel="#L828">828</span>
<span id="L829" rel="#L829">829</span>
<span id="L830" rel="#L830">830</span>
<span id="L831" rel="#L831">831</span>
<span id="L832" rel="#L832">832</span>
<span id="L833" rel="#L833">833</span>
<span id="L834" rel="#L834">834</span>
<span id="L835" rel="#L835">835</span>
<span id="L836" rel="#L836">836</span>
<span id="L837" rel="#L837">837</span>
<span id="L838" rel="#L838">838</span>
<span id="L839" rel="#L839">839</span>
<span id="L840" rel="#L840">840</span>
<span id="L841" rel="#L841">841</span>
<span id="L842" rel="#L842">842</span>
<span id="L843" rel="#L843">843</span>
<span id="L844" rel="#L844">844</span>
<span id="L845" rel="#L845">845</span>
<span id="L846" rel="#L846">846</span>
<span id="L847" rel="#L847">847</span>
<span id="L848" rel="#L848">848</span>
<span id="L849" rel="#L849">849</span>
<span id="L850" rel="#L850">850</span>
<span id="L851" rel="#L851">851</span>
<span id="L852" rel="#L852">852</span>
<span id="L853" rel="#L853">853</span>
<span id="L854" rel="#L854">854</span>
<span id="L855" rel="#L855">855</span>
<span id="L856" rel="#L856">856</span>
<span id="L857" rel="#L857">857</span>
<span id="L858" rel="#L858">858</span>
<span id="L859" rel="#L859">859</span>
<span id="L860" rel="#L860">860</span>
<span id="L861" rel="#L861">861</span>
<span id="L862" rel="#L862">862</span>
<span id="L863" rel="#L863">863</span>
<span id="L864" rel="#L864">864</span>
<span id="L865" rel="#L865">865</span>
<span id="L866" rel="#L866">866</span>
<span id="L867" rel="#L867">867</span>
<span id="L868" rel="#L868">868</span>
<span id="L869" rel="#L869">869</span>
<span id="L870" rel="#L870">870</span>
<span id="L871" rel="#L871">871</span>
<span id="L872" rel="#L872">872</span>
<span id="L873" rel="#L873">873</span>

            </td>
            <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="c1">//</span></div><div class='line' id='LC2'><span class="c1">// Lighthouse3D.com OpenGL 3.3 + GLSL 3.3 Sample</span></div><div class='line' id='LC3'><span class="c1">//</span></div><div class='line' id='LC4'><span class="c1">// Loading and displaying a Textured Model</span></div><div class='line' id='LC5'><span class="c1">//</span></div><div class='line' id='LC6'><span class="c1">// Uses:</span></div><div class='line' id='LC7'><span class="c1">//  Assimp lybrary for model loading</span></div><div class='line' id='LC8'><span class="c1">//		http://assimp.sourceforge.net/</span></div><div class='line' id='LC9'><span class="c1">//  Devil for image loading</span></div><div class='line' id='LC10'><span class="c1">//		http://openil.sourceforge.net/</span></div><div class='line' id='LC11'><span class="c1">//	Uniform Blocks</span></div><div class='line' id='LC12'><span class="c1">//  Vertex Array Objects</span></div><div class='line' id='LC13'><span class="c1">//</span></div><div class='line' id='LC14'><span class="c1">// Some parts of the code are strongly based on the Assimp </span></div><div class='line' id='LC15'><span class="c1">// SimpleTextureOpenGL sample that comes with the Assimp </span></div><div class='line' id='LC16'><span class="c1">// distribution, namely the code that relates to loading the images</span></div><div class='line' id='LC17'><span class="c1">// and the model.</span></div><div class='line' id='LC18'><span class="c1">//</span></div><div class='line' id='LC19'><span class="c1">// The code was updated and modified to be compatible with </span></div><div class='line' id='LC20'><span class="c1">// OpenGL 3.3 CORE version</span></div><div class='line' id='LC21'><br/></div><div class='line' id='LC22'><br/></div><div class='line' id='LC23'><span class="cp">#ifdef _WIN32</span></div><div class='line' id='LC24'><span class="cp">#pragma comment(lib,&quot;assimp.lib&quot;)</span></div><div class='line' id='LC25'><span class="cp">#pragma comment(lib,&quot;devil.lib&quot;)</span></div><div class='line' id='LC26'><span class="cp">#pragma comment(lib,&quot;glew32.lib&quot;)</span></div><div class='line' id='LC27'><span class="cp">#endif</span></div><div class='line' id='LC28'><br/></div><div class='line' id='LC29'><span class="cp">#include &quot;AssimpRenderer.h&quot;</span></div><div class='line' id='LC30'><br/></div><div class='line' id='LC31'><span class="k">static</span> <span class="kr">inline</span> <span class="kt">float</span> <span class="nf">DegToRad</span><span class="p">(</span><span class="kt">float</span> <span class="n">degrees</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC32'>&nbsp;&nbsp;<span class="k">return</span> <span class="p">(</span><span class="kt">float</span><span class="p">)(</span><span class="n">degrees</span> <span class="o">*</span> <span class="p">(</span><span class="n">M_PI</span> <span class="o">/</span> <span class="mf">180.0f</span><span class="p">));</span></div><div class='line' id='LC33'><span class="p">}</span></div><div class='line' id='LC34'><br/></div><div class='line' id='LC35'><span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">AssimpRenderer</span><span class="p">(</span><span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">ARSceneFile</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC36'>&nbsp;&nbsp;<span class="c1">// Vertex Attribute Locations</span></div><div class='line' id='LC37'>&nbsp;&nbsp;<span class="n">vertexLoc</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC38'>&nbsp;&nbsp;<span class="n">normalLoc</span><span class="o">=</span><span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC39'>&nbsp;&nbsp;<span class="n">texCoordLoc</span><span class="o">=</span><span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC40'><br/></div><div class='line' id='LC41'>&nbsp;&nbsp;<span class="c1">// Uniform Bindings Points</span></div><div class='line' id='LC42'>&nbsp;&nbsp;<span class="n">matricesUniLoc</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC43'>&nbsp;&nbsp;<span class="n">materialUniLoc</span> <span class="o">=</span> <span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC44'><br/></div><div class='line' id='LC45'>&nbsp;&nbsp;<span class="c1">// The sampler uniform for textured models</span></div><div class='line' id='LC46'>&nbsp;&nbsp;<span class="c1">// we are assuming a single texture so this will</span></div><div class='line' id='LC47'>&nbsp;&nbsp;<span class="c1">//always be texture unit 0</span></div><div class='line' id='LC48'>&nbsp;&nbsp;<span class="n">texUnit</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC49'><br/></div><div class='line' id='LC50'>&nbsp;&nbsp;<span class="c1">// the global Assimp scene object</span></div><div class='line' id='LC51'>&nbsp;&nbsp;<span class="n">scene</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC52'><br/></div><div class='line' id='LC53'>&nbsp;&nbsp;<span class="c1">// Camera Position</span></div><div class='line' id='LC54'>&nbsp;&nbsp;<span class="n">camX</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">camY</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">camZ</span> <span class="o">=</span> <span class="mi">5</span><span class="p">;</span></div><div class='line' id='LC55'><br/></div><div class='line' id='LC56'>&nbsp;&nbsp;<span class="c1">// Camera Spherical Coordinates</span></div><div class='line' id='LC57'>&nbsp;&nbsp;<span class="n">alpha</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="n">beta</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC58'>&nbsp;&nbsp;<span class="n">r</span> <span class="o">=</span> <span class="mf">5.0f</span><span class="p">;</span></div><div class='line' id='LC59'><br/></div><div class='line' id='LC60'>&nbsp;&nbsp;<span class="c1">// Frame counting and FPS computation</span></div><div class='line' id='LC61'>&nbsp;&nbsp;<span class="n">timebase</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span><span class="n">frame</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC62'><br/></div><div class='line' id='LC63'>&nbsp;&nbsp;<span class="c1">// Set the object to load :</span></div><div class='line' id='LC64'>&nbsp;&nbsp;<span class="n">modelname</span> <span class="o">=</span> <span class="n">ARSceneFile</span><span class="p">;</span></div><div class='line' id='LC65'>&nbsp;&nbsp;<span class="n">importer</span> <span class="o">=</span> <span class="k">new</span> <span class="n">Assimp</span><span class="o">::</span><span class="n">Importer</span><span class="p">();</span></div><div class='line' id='LC66'><span class="p">}</span></div><div class='line' id='LC67'><br/></div><div class='line' id='LC68'><span class="n">AssimpRenderer</span><span class="o">::~</span><span class="n">AssimpRenderer</span><span class="p">()</span></div><div class='line' id='LC69'><span class="p">{</span></div><div class='line' id='LC70'>&nbsp;&nbsp;<span class="c1">// cleaning up</span></div><div class='line' id='LC71'>&nbsp;&nbsp;<span class="n">textureIdMap</span><span class="p">.</span><span class="n">clear</span><span class="p">();</span></div><div class='line' id='LC72'><br/></div><div class='line' id='LC73'>&nbsp;&nbsp;<span class="c1">// clear myMeshes stuff</span></div><div class='line' id='LC74'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">myMeshes</span><span class="p">.</span><span class="n">size</span><span class="p">();</span> <span class="o">++</span><span class="n">i</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC75'><br/></div><div class='line' id='LC76'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glDeleteVertexArrays</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="o">&amp;</span><span class="p">(</span><span class="n">myMeshes</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">vao</span><span class="p">));</span></div><div class='line' id='LC77'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glDeleteTextures</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="o">&amp;</span><span class="p">(</span><span class="n">myMeshes</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">texIndex</span><span class="p">));</span></div><div class='line' id='LC78'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glDeleteBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="o">&amp;</span><span class="p">(</span><span class="n">myMeshes</span><span class="p">[</span><span class="n">i</span><span class="p">].</span><span class="n">uniformBlockIndex</span><span class="p">));</span></div><div class='line' id='LC79'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC80'>&nbsp;&nbsp;<span class="c1">// delete buffers</span></div><div class='line' id='LC81'>&nbsp;&nbsp;<span class="n">glDeleteBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="o">&amp;</span><span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC82'><span class="p">}</span></div><div class='line' id='LC83'><br/></div><div class='line' id='LC84'><span class="c1">// Setup</span></div><div class='line' id='LC85'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">buildProjectionMatrix</span><span class="p">(</span><span class="kt">float</span> <span class="n">fov</span><span class="p">,</span> <span class="kt">float</span> <span class="n">ratio</span><span class="p">,</span> <span class="kt">float</span> <span class="n">nearp</span><span class="p">,</span> <span class="kt">float</span> <span class="n">farp</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC86'><br/></div><div class='line' id='LC87'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">projMatrix</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC88'><br/></div><div class='line' id='LC89'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">f</span> <span class="o">=</span> <span class="mf">1.0f</span> <span class="o">/</span> <span class="n">tan</span> <span class="p">(</span><span class="n">fov</span> <span class="o">*</span> <span class="p">(</span><span class="n">M_PI</span> <span class="o">/</span> <span class="mf">360.0f</span><span class="p">));</span></div><div class='line' id='LC90'><br/></div><div class='line' id='LC91'>&nbsp;&nbsp;<span class="n">setIdentityMatrix</span><span class="p">(</span><span class="n">projMatrix</span><span class="p">,</span><span class="mi">4</span><span class="p">);</span></div><div class='line' id='LC92'><br/></div><div class='line' id='LC93'>&nbsp;&nbsp;<span class="n">projMatrix</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="n">f</span> <span class="o">/</span> <span class="n">ratio</span><span class="p">;</span></div><div class='line' id='LC94'>&nbsp;&nbsp;<span class="n">projMatrix</span><span class="p">[</span><span class="mi">1</span> <span class="o">*</span> <span class="mi">4</span> <span class="o">+</span> <span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">f</span><span class="p">;</span></div><div class='line' id='LC95'>&nbsp;&nbsp;<span class="n">projMatrix</span><span class="p">[</span><span class="mi">2</span> <span class="o">*</span> <span class="mi">4</span> <span class="o">+</span> <span class="mi">2</span><span class="p">]</span> <span class="o">=</span> <span class="p">(</span><span class="n">farp</span> <span class="o">+</span> <span class="n">nearp</span><span class="p">)</span> <span class="o">/</span> <span class="p">(</span><span class="n">nearp</span> <span class="o">-</span> <span class="n">farp</span><span class="p">);</span></div><div class='line' id='LC96'>&nbsp;&nbsp;<span class="n">projMatrix</span><span class="p">[</span><span class="mi">3</span> <span class="o">*</span> <span class="mi">4</span> <span class="o">+</span> <span class="mi">2</span><span class="p">]</span> <span class="o">=</span> <span class="p">(</span><span class="mf">2.0f</span> <span class="o">*</span> <span class="n">farp</span> <span class="o">*</span> <span class="n">nearp</span><span class="p">)</span> <span class="o">/</span> <span class="p">(</span><span class="n">nearp</span> <span class="o">-</span> <span class="n">farp</span><span class="p">);</span></div><div class='line' id='LC97'>&nbsp;&nbsp;<span class="n">projMatrix</span><span class="p">[</span><span class="mi">2</span> <span class="o">*</span> <span class="mi">4</span> <span class="o">+</span> <span class="mi">3</span><span class="p">]</span> <span class="o">=</span> <span class="o">-</span><span class="mf">1.0f</span><span class="p">;</span></div><div class='line' id='LC98'>&nbsp;&nbsp;<span class="n">projMatrix</span><span class="p">[</span><span class="mi">3</span> <span class="o">*</span> <span class="mi">4</span> <span class="o">+</span> <span class="mi">3</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC99'><br/></div><div class='line' id='LC100'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC101'>&nbsp;&nbsp;<span class="n">glBufferSubData</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">ProjMatrixOffset</span><span class="p">,</span> <span class="n">MatrixSize</span><span class="p">,</span> <span class="n">projMatrix</span><span class="p">);</span></div><div class='line' id='LC102'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC103'><span class="p">}</span></div><div class='line' id='LC104'><br/></div><div class='line' id='LC105'><br/></div><div class='line' id='LC106'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">crossProduct</span><span class="p">(</span> <span class="kt">float</span> <span class="o">*</span><span class="n">a</span><span class="p">,</span> <span class="kt">float</span> <span class="o">*</span><span class="n">b</span><span class="p">,</span> <span class="kt">float</span> <span class="o">*</span><span class="n">res</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC107'><br/></div><div class='line' id='LC108'>&nbsp;&nbsp;<span class="n">res</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="n">a</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">*</span> <span class="n">b</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span>  <span class="o">-</span>  <span class="n">b</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">*</span> <span class="n">a</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC109'>&nbsp;&nbsp;<span class="n">res</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">a</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">*</span> <span class="n">b</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span>  <span class="o">-</span>  <span class="n">b</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">*</span> <span class="n">a</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC110'>&nbsp;&nbsp;<span class="n">res</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">=</span> <span class="n">a</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">*</span> <span class="n">b</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span>  <span class="o">-</span>  <span class="n">b</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">*</span> <span class="n">a</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC111'><span class="p">}</span></div><div class='line' id='LC112'><br/></div><div class='line' id='LC113'><span class="c1">// Model loading and OpenGL setup</span></div><div class='line' id='LC114'><span class="kt">bool</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">init</span><span class="p">()</span></div><div class='line' id='LC115'><span class="p">{</span></div><div class='line' id='LC116'>&nbsp;&nbsp;<span class="c1">// Load a model if needed</span></div><div class='line' id='LC117'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">modelname</span><span class="p">.</span><span class="n">empty</span><span class="p">())</span> <span class="p">{</span></div><div class='line' id='LC118'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer: No model defined, quitting&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC119'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="nb">false</span><span class="p">;</span></div><div class='line' id='LC120'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC121'><br/></div><div class='line' id='LC122'>&nbsp;&nbsp;<span class="n">import3DFromFile</span><span class="p">(</span><span class="n">modelname</span><span class="p">);</span> <span class="c1">// defines Assimp &quot;scene&quot;</span></div><div class='line' id='LC123'>&nbsp;&nbsp;<span class="n">loadGLTextures</span><span class="p">(</span><span class="n">scene</span><span class="p">);</span></div><div class='line' id='LC124'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer: Model loaded&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC125'><br/></div><div class='line' id='LC126'>&nbsp;&nbsp;<span class="n">program</span> <span class="o">=</span> <span class="n">setupShaders</span><span class="p">();</span></div><div class='line' id='LC127'>&nbsp;&nbsp;<span class="n">genVAOsAndUniformBuffer</span><span class="p">(</span><span class="n">scene</span><span class="p">);</span> <span class="c1">// Generate Vertex Arrays Objects and buffers</span></div><div class='line' id='LC128'><br/></div><div class='line' id='LC129'>&nbsp;&nbsp;<span class="n">glEnable</span><span class="p">(</span><span class="n">GL_DEPTH_TEST</span><span class="p">);</span></div><div class='line' id='LC130'>&nbsp;&nbsp;<span class="n">glClearColor</span><span class="p">(</span><span class="mf">1.0f</span><span class="p">,</span> <span class="mf">1.0f</span><span class="p">,</span> <span class="mf">1.0f</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">);</span></div><div class='line' id='LC131'><br/></div><div class='line' id='LC132'>&nbsp;&nbsp;<span class="n">glGenBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="o">&amp;</span><span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC133'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC134'>&nbsp;&nbsp;<span class="n">glBufferData</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">MatricesUniBufferSize</span><span class="p">,</span><span class="nb">NULL</span><span class="p">,</span><span class="n">GL_DYNAMIC_DRAW</span><span class="p">);</span></div><div class='line' id='LC135'>&nbsp;&nbsp;<span class="n">glBindBufferRange</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">matricesUniLoc</span><span class="p">,</span> <span class="n">matricesUniBuffer</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">MatricesUniBufferSize</span><span class="p">);</span></div><div class='line' id='LC136'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC137'>&nbsp;&nbsp;<span class="n">glEnable</span><span class="p">(</span><span class="n">GL_MULTISAMPLE</span><span class="p">);</span></div><div class='line' id='LC138'><br/></div><div class='line' id='LC139'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer: Initialized&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC140'>&nbsp;&nbsp;<span class="k">return</span> <span class="nb">true</span><span class="p">;</span></div><div class='line' id='LC141'><span class="p">}</span></div><div class='line' id='LC142'><br/></div><div class='line' id='LC143'><br/></div><div class='line' id='LC144'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">genVAOsAndUniformBuffer</span><span class="p">(</span><span class="k">const</span> <span class="n">aiScene</span> <span class="o">*</span><span class="n">sc</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC145'>&nbsp;&nbsp;<span class="k">struct</span> <span class="n">MyMesh</span> <span class="n">aMesh</span><span class="p">;</span></div><div class='line' id='LC146'>&nbsp;&nbsp;<span class="k">struct</span> <span class="n">MyMaterial</span> <span class="n">aMat</span><span class="p">;</span></div><div class='line' id='LC147'>&nbsp;&nbsp;<span class="n">GLuint</span> <span class="n">buffer</span><span class="p">;</span></div><div class='line' id='LC148'><br/></div><div class='line' id='LC149'>&nbsp;&nbsp;<span class="c1">// For each mesh</span></div><div class='line' id='LC150'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">n</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">n</span> <span class="o">&lt;</span> <span class="n">sc</span><span class="o">-&gt;</span><span class="n">mNumMeshes</span><span class="p">;</span> <span class="o">++</span><span class="n">n</span><span class="p">)</span></div><div class='line' id='LC151'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC152'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="n">aiMesh</span><span class="o">*</span> <span class="n">mesh</span> <span class="o">=</span> <span class="n">sc</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">n</span><span class="p">];</span></div><div class='line' id='LC153'><br/></div><div class='line' id='LC154'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// create array with faces</span></div><div class='line' id='LC155'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// have to convert from Assimp format to array</span></div><div class='line' id='LC156'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">*</span><span class="n">faceArray</span><span class="p">;</span></div><div class='line' id='LC157'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">faceArray</span> <span class="o">=</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">*</span><span class="p">)</span><span class="n">malloc</span><span class="p">(</span><span class="k">sizeof</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span> <span class="o">*</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumFaces</span> <span class="o">*</span> <span class="mi">3</span><span class="p">);</span></div><div class='line' id='LC158'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">faceIndex</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC159'><br/></div><div class='line' id='LC160'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">t</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">t</span> <span class="o">&lt;</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumFaces</span><span class="p">;</span> <span class="o">++</span><span class="n">t</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC161'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="n">aiFace</span><span class="o">*</span> <span class="n">face</span> <span class="o">=</span> <span class="o">&amp;</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mFaces</span><span class="p">[</span><span class="n">t</span><span class="p">];</span></div><div class='line' id='LC162'><br/></div><div class='line' id='LC163'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="o">&amp;</span><span class="n">faceArray</span><span class="p">[</span><span class="n">faceIndex</span><span class="p">],</span> <span class="n">face</span><span class="o">-&gt;</span><span class="n">mIndices</span><span class="p">,</span><span class="mi">3</span> <span class="o">*</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">));</span></div><div class='line' id='LC164'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">faceIndex</span> <span class="o">+=</span> <span class="mi">3</span><span class="p">;</span></div><div class='line' id='LC165'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC166'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aMesh</span><span class="p">.</span><span class="n">numFaces</span> <span class="o">=</span> <span class="n">sc</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">n</span><span class="p">]</span><span class="o">-&gt;</span><span class="n">mNumFaces</span><span class="p">;</span></div><div class='line' id='LC167'><br/></div><div class='line' id='LC168'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// generate Vertex Array for mesh</span></div><div class='line' id='LC169'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGenVertexArrays</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="o">&amp;</span><span class="p">(</span><span class="n">aMesh</span><span class="p">.</span><span class="n">vao</span><span class="p">));</span></div><div class='line' id='LC170'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindVertexArray</span><span class="p">(</span><span class="n">aMesh</span><span class="p">.</span><span class="n">vao</span><span class="p">);</span></div><div class='line' id='LC171'><br/></div><div class='line' id='LC172'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// buffer for faces</span></div><div class='line' id='LC173'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGenBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC174'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_ELEMENT_ARRAY_BUFFER</span><span class="p">,</span> <span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC175'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBufferData</span><span class="p">(</span><span class="n">GL_ELEMENT_ARRAY_BUFFER</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span><span class="p">)</span> <span class="o">*</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumFaces</span> <span class="o">*</span> <span class="mi">3</span><span class="p">,</span> <span class="n">faceArray</span><span class="p">,</span> <span class="n">GL_STATIC_DRAW</span><span class="p">);</span></div><div class='line' id='LC176'><br/></div><div class='line' id='LC177'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// buffer for vertex positions</span></div><div class='line' id='LC178'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">HasPositions</span><span class="p">())</span> <span class="p">{</span></div><div class='line' id='LC179'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGenBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC180'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_ARRAY_BUFFER</span><span class="p">,</span> <span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC181'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBufferData</span><span class="p">(</span><span class="n">GL_ARRAY_BUFFER</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="o">*</span><span class="mi">3</span><span class="o">*</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumVertices</span><span class="p">,</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mVertices</span><span class="p">,</span> <span class="n">GL_STATIC_DRAW</span><span class="p">);</span></div><div class='line' id='LC182'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glEnableVertexAttribArray</span><span class="p">(</span><span class="n">vertexLoc</span><span class="p">);</span></div><div class='line' id='LC183'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glVertexAttribPointer</span><span class="p">(</span><span class="n">vertexLoc</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="n">GL_FLOAT</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC184'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC185'><br/></div><div class='line' id='LC186'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// buffer for vertex normals</span></div><div class='line' id='LC187'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">HasNormals</span><span class="p">())</span> <span class="p">{</span></div><div class='line' id='LC188'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGenBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC189'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_ARRAY_BUFFER</span><span class="p">,</span> <span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC190'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBufferData</span><span class="p">(</span><span class="n">GL_ARRAY_BUFFER</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="o">*</span><span class="mi">3</span><span class="o">*</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumVertices</span><span class="p">,</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNormals</span><span class="p">,</span> <span class="n">GL_STATIC_DRAW</span><span class="p">);</span></div><div class='line' id='LC191'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glEnableVertexAttribArray</span><span class="p">(</span><span class="n">normalLoc</span><span class="p">);</span></div><div class='line' id='LC192'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glVertexAttribPointer</span><span class="p">(</span><span class="n">normalLoc</span><span class="p">,</span> <span class="mi">3</span><span class="p">,</span> <span class="n">GL_FLOAT</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC193'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC194'><br/></div><div class='line' id='LC195'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// buffer for vertex texture coordinates</span></div><div class='line' id='LC196'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">HasTextureCoords</span><span class="p">(</span><span class="mi">0</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC197'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="o">*</span><span class="n">texCoords</span> <span class="o">=</span> <span class="p">(</span><span class="kt">float</span> <span class="o">*</span><span class="p">)</span><span class="n">malloc</span><span class="p">(</span><span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="o">*</span><span class="mi">2</span><span class="o">*</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumVertices</span><span class="p">);</span></div><div class='line' id='LC198'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">k</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">k</span> <span class="o">&lt;</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumVertices</span><span class="p">;</span> <span class="o">++</span><span class="n">k</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC199'><br/></div><div class='line' id='LC200'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">texCoords</span><span class="p">[</span><span class="n">k</span><span class="o">*</span><span class="mi">2</span><span class="p">]</span>   <span class="o">=</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mTextureCoords</span><span class="p">[</span><span class="mi">0</span><span class="p">][</span><span class="n">k</span><span class="p">].</span><span class="n">x</span><span class="p">;</span></div><div class='line' id='LC201'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">texCoords</span><span class="p">[</span><span class="n">k</span><span class="o">*</span><span class="mi">2</span><span class="o">+</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mTextureCoords</span><span class="p">[</span><span class="mi">0</span><span class="p">][</span><span class="n">k</span><span class="p">].</span><span class="n">y</span><span class="p">;</span></div><div class='line' id='LC202'><br/></div><div class='line' id='LC203'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC204'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGenBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC205'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_ARRAY_BUFFER</span><span class="p">,</span> <span class="n">buffer</span><span class="p">);</span></div><div class='line' id='LC206'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBufferData</span><span class="p">(</span><span class="n">GL_ARRAY_BUFFER</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="o">*</span><span class="mi">2</span><span class="o">*</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumVertices</span><span class="p">,</span> <span class="n">texCoords</span><span class="p">,</span> <span class="n">GL_STATIC_DRAW</span><span class="p">);</span></div><div class='line' id='LC207'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glEnableVertexAttribArray</span><span class="p">(</span><span class="n">texCoordLoc</span><span class="p">);</span></div><div class='line' id='LC208'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glVertexAttribPointer</span><span class="p">(</span><span class="n">texCoordLoc</span><span class="p">,</span> <span class="mi">2</span><span class="p">,</span> <span class="n">GL_FLOAT</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC209'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC210'><br/></div><div class='line' id='LC211'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// unbind buffers</span></div><div class='line' id='LC212'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindVertexArray</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC213'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_ARRAY_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC214'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_ELEMENT_ARRAY_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC215'><br/></div><div class='line' id='LC216'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// create material uniform buffer</span></div><div class='line' id='LC217'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiMaterial</span> <span class="o">*</span><span class="n">mtl</span> <span class="o">=</span> <span class="n">sc</span><span class="o">-&gt;</span><span class="n">mMaterials</span><span class="p">[</span><span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mMaterialIndex</span><span class="p">];</span></div><div class='line' id='LC218'><br/></div><div class='line' id='LC219'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiString</span> <span class="n">texPath</span><span class="p">;</span>	<span class="c1">//contains filename of texture</span></div><div class='line' id='LC220'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span><span class="n">AI_SUCCESS</span> <span class="o">==</span> <span class="n">mtl</span><span class="o">-&gt;</span><span class="n">GetTexture</span><span class="p">(</span><span class="n">aiTextureType_DIFFUSE</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">texPath</span><span class="p">)){</span></div><div class='line' id='LC221'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//bind texture</span></div><div class='line' id='LC222'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">texId</span> <span class="o">=</span> <span class="n">textureIdMap</span><span class="p">[</span><span class="n">texPath</span><span class="p">.</span><span class="n">data</span><span class="p">];</span></div><div class='line' id='LC223'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aMesh</span><span class="p">.</span><span class="n">texIndex</span> <span class="o">=</span> <span class="n">texId</span><span class="p">;</span></div><div class='line' id='LC224'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aMat</span><span class="p">.</span><span class="n">texCount</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC225'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC226'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">else</span></div><div class='line' id='LC227'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aMat</span><span class="p">.</span><span class="n">texCount</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC228'><br/></div><div class='line' id='LC229'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">c</span><span class="p">[</span><span class="mi">4</span><span class="p">];</span></div><div class='line' id='LC230'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">set_float4</span><span class="p">(</span><span class="n">c</span><span class="p">,</span> <span class="mf">0.8f</span><span class="p">,</span> <span class="mf">0.8f</span><span class="p">,</span> <span class="mf">0.8f</span><span class="p">,</span> <span class="mf">1.0f</span><span class="p">);</span></div><div class='line' id='LC231'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiColor4D</span> <span class="n">diffuse</span><span class="p">;</span></div><div class='line' id='LC232'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span><span class="n">AI_SUCCESS</span> <span class="o">==</span> <span class="n">aiGetMaterialColor</span><span class="p">(</span><span class="n">mtl</span><span class="p">,</span> <span class="n">AI_MATKEY_COLOR_DIFFUSE</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">diffuse</span><span class="p">))</span></div><div class='line' id='LC233'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">color4_to_float4</span><span class="p">(</span><span class="o">&amp;</span><span class="n">diffuse</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC234'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">aMat</span><span class="p">.</span><span class="n">diffuse</span><span class="p">,</span> <span class="n">c</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">c</span><span class="p">));</span></div><div class='line' id='LC235'><br/></div><div class='line' id='LC236'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">set_float4</span><span class="p">(</span><span class="n">c</span><span class="p">,</span> <span class="mf">0.2f</span><span class="p">,</span> <span class="mf">0.2f</span><span class="p">,</span> <span class="mf">0.2f</span><span class="p">,</span> <span class="mf">1.0f</span><span class="p">);</span></div><div class='line' id='LC237'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiColor4D</span> <span class="n">ambient</span><span class="p">;</span></div><div class='line' id='LC238'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span><span class="n">AI_SUCCESS</span> <span class="o">==</span> <span class="n">aiGetMaterialColor</span><span class="p">(</span><span class="n">mtl</span><span class="p">,</span> <span class="n">AI_MATKEY_COLOR_AMBIENT</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">ambient</span><span class="p">))</span></div><div class='line' id='LC239'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">color4_to_float4</span><span class="p">(</span><span class="o">&amp;</span><span class="n">ambient</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC240'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">aMat</span><span class="p">.</span><span class="n">ambient</span><span class="p">,</span> <span class="n">c</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">c</span><span class="p">));</span></div><div class='line' id='LC241'><br/></div><div class='line' id='LC242'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">set_float4</span><span class="p">(</span><span class="n">c</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="mf">1.0f</span><span class="p">);</span></div><div class='line' id='LC243'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiColor4D</span> <span class="n">specular</span><span class="p">;</span></div><div class='line' id='LC244'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span><span class="n">AI_SUCCESS</span> <span class="o">==</span> <span class="n">aiGetMaterialColor</span><span class="p">(</span><span class="n">mtl</span><span class="p">,</span> <span class="n">AI_MATKEY_COLOR_SPECULAR</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">specular</span><span class="p">))</span></div><div class='line' id='LC245'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">color4_to_float4</span><span class="p">(</span><span class="o">&amp;</span><span class="n">specular</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC246'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">aMat</span><span class="p">.</span><span class="n">specular</span><span class="p">,</span> <span class="n">c</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">c</span><span class="p">));</span></div><div class='line' id='LC247'><br/></div><div class='line' id='LC248'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">set_float4</span><span class="p">(</span><span class="n">c</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="mf">1.0f</span><span class="p">);</span></div><div class='line' id='LC249'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiColor4D</span> <span class="n">emission</span><span class="p">;</span></div><div class='line' id='LC250'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span><span class="n">AI_SUCCESS</span> <span class="o">==</span> <span class="n">aiGetMaterialColor</span><span class="p">(</span><span class="n">mtl</span><span class="p">,</span> <span class="n">AI_MATKEY_COLOR_EMISSIVE</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">emission</span><span class="p">))</span></div><div class='line' id='LC251'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">color4_to_float4</span><span class="p">(</span><span class="o">&amp;</span><span class="n">emission</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC252'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">aMat</span><span class="p">.</span><span class="n">emissive</span><span class="p">,</span> <span class="n">c</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">c</span><span class="p">));</span></div><div class='line' id='LC253'><br/></div><div class='line' id='LC254'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">shininess</span> <span class="o">=</span> <span class="mf">0.0</span><span class="p">;</span></div><div class='line' id='LC255'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">max</span><span class="p">;</span></div><div class='line' id='LC256'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiGetMaterialFloatArray</span><span class="p">(</span><span class="n">mtl</span><span class="p">,</span> <span class="n">AI_MATKEY_SHININESS</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">shininess</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">max</span><span class="p">);</span></div><div class='line' id='LC257'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aMat</span><span class="p">.</span><span class="n">shininess</span> <span class="o">=</span> <span class="n">shininess</span><span class="p">;</span></div><div class='line' id='LC258'><br/></div><div class='line' id='LC259'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGenBuffers</span><span class="p">(</span><span class="mi">1</span><span class="p">,</span><span class="o">&amp;</span><span class="p">(</span><span class="n">aMesh</span><span class="p">.</span><span class="n">uniformBlockIndex</span><span class="p">));</span></div><div class='line' id='LC260'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="n">aMesh</span><span class="p">.</span><span class="n">uniformBlockIndex</span><span class="p">);</span></div><div class='line' id='LC261'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBufferData</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="n">aMat</span><span class="p">),</span> <span class="p">(</span><span class="kt">void</span> <span class="o">*</span><span class="p">)(</span><span class="o">&amp;</span><span class="n">aMat</span><span class="p">),</span> <span class="n">GL_STATIC_DRAW</span><span class="p">);</span></div><div class='line' id='LC262'><br/></div><div class='line' id='LC263'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">myMeshes</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">aMesh</span><span class="p">);</span></div><div class='line' id='LC264'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC265'><span class="p">}</span></div><div class='line' id='LC266'><br/></div><div class='line' id='LC267'><br/></div><div class='line' id='LC268'><span class="c1">// Parse the Model file</span></div><div class='line' id='LC269'><span class="kt">bool</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">import3DFromFile</span><span class="p">(</span><span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span><span class="o">&amp;</span> <span class="n">pFile</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC270'><br/></div><div class='line' id='LC271'>&nbsp;&nbsp;<span class="c1">//check if file exists</span></div><div class='line' id='LC272'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">ifstream</span> <span class="n">fin</span><span class="p">(</span><span class="n">pFile</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></div><div class='line' id='LC273'>&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span><span class="o">!</span><span class="n">fin</span><span class="p">.</span><span class="n">fail</span><span class="p">())</span> <span class="p">{</span></div><div class='line' id='LC274'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">fin</span><span class="p">.</span><span class="n">close</span><span class="p">();</span></div><div class='line' id='LC275'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span><span class="p">{</span></div><div class='line' id='LC276'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;Couldn&#39;t open file: &quot;</span><span class="o">&lt;&lt;</span> <span class="n">pFile</span><span class="p">.</span><span class="n">c_str</span><span class="p">()</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC277'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="n">importer</span><span class="o">-&gt;</span><span class="n">GetErrorString</span><span class="p">()</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC278'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="nb">false</span><span class="p">;</span></div><div class='line' id='LC279'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC280'><br/></div><div class='line' id='LC281'>&nbsp;&nbsp;<span class="c1">// Import the scene using Assimp C++ API</span></div><div class='line' id='LC282'>&nbsp;&nbsp;<span class="n">scene</span> <span class="o">=</span> <span class="n">importer</span><span class="o">-&gt;</span><span class="n">ReadFile</span><span class="p">(</span><span class="n">pFile</span><span class="p">,</span> <span class="n">aiProcessPreset_TargetRealtime_Quality</span><span class="p">);</span></div><div class='line' id='LC283'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer : Scene &quot;</span> <span class="o">&lt;&lt;</span> <span class="n">pFile</span> <span class="o">&lt;&lt;</span> <span class="s">&quot; import is OK&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC284'><br/></div><div class='line' id='LC285'>&nbsp;&nbsp;<span class="c1">// If the import failed, report it</span></div><div class='line' id='LC286'>&nbsp;&nbsp;<span class="k">if</span><span class="p">(</span> <span class="o">!</span><span class="n">scene</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC287'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="n">importer</span><span class="o">-&gt;</span><span class="n">GetErrorString</span><span class="p">()</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC288'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">return</span> <span class="nb">false</span><span class="p">;</span></div><div class='line' id='LC289'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC290'><br/></div><div class='line' id='LC291'>&nbsp;&nbsp;<span class="c1">// Now we can access the file&#39;s contents.</span></div><div class='line' id='LC292'>&nbsp;&nbsp;<span class="n">aiVector3D</span> <span class="n">scene_min</span><span class="p">,</span> <span class="n">scene_max</span><span class="p">;</span></div><div class='line' id='LC293'>&nbsp;&nbsp;<span class="n">get_bounding_box</span><span class="p">(</span><span class="o">&amp;</span><span class="n">scene_min</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">scene_max</span><span class="p">);</span></div><div class='line' id='LC294'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">tmp</span><span class="p">;</span></div><div class='line' id='LC295'>&nbsp;&nbsp;<span class="n">tmp</span> <span class="o">=</span> <span class="n">scene_max</span><span class="p">.</span><span class="n">x</span><span class="o">-</span><span class="n">scene_min</span><span class="p">.</span><span class="n">x</span><span class="p">;</span></div><div class='line' id='LC296'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer : Model scale &quot;</span> <span class="o">&lt;&lt;</span> <span class="n">tmp</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC297'>&nbsp;&nbsp;<span class="n">tmp</span> <span class="o">=</span> <span class="n">scene_max</span><span class="p">.</span><span class="n">y</span> <span class="o">-</span> <span class="n">scene_min</span><span class="p">.</span><span class="n">y</span> <span class="o">&gt;</span> <span class="n">tmp</span><span class="o">?</span><span class="n">scene_max</span><span class="p">.</span><span class="n">y</span> <span class="o">-</span> <span class="n">scene_min</span><span class="p">.</span><span class="n">y</span><span class="o">:</span><span class="n">tmp</span><span class="p">;</span></div><div class='line' id='LC298'>&nbsp;&nbsp;<span class="n">tmp</span> <span class="o">=</span> <span class="n">scene_max</span><span class="p">.</span><span class="n">z</span> <span class="o">-</span> <span class="n">scene_min</span><span class="p">.</span><span class="n">z</span> <span class="o">&gt;</span> <span class="n">tmp</span><span class="o">?</span><span class="n">scene_max</span><span class="p">.</span><span class="n">z</span> <span class="o">-</span> <span class="n">scene_min</span><span class="p">.</span><span class="n">z</span><span class="o">:</span><span class="n">tmp</span><span class="p">;</span></div><div class='line' id='LC299'>&nbsp;&nbsp;<span class="n">scaleFactor</span> <span class="o">=</span> <span class="mf">1.f</span> <span class="o">/</span> <span class="n">tmp</span><span class="p">;</span></div><div class='line' id='LC300'><br/></div><div class='line' id='LC301'>&nbsp;&nbsp;<span class="c1">// We&#39;re done. Everything will be cleaned up by the importer destructor</span></div><div class='line' id='LC302'>&nbsp;&nbsp;<span class="k">return</span> <span class="nb">true</span><span class="p">;</span></div><div class='line' id='LC303'><span class="p">}</span></div><div class='line' id='LC304'><br/></div><div class='line' id='LC305'><span class="kt">int</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">loadGLTextures</span><span class="p">(</span><span class="k">const</span> <span class="n">aiScene</span><span class="o">*</span> <span class="n">scene</span><span class="p">)</span></div><div class='line' id='LC306'><span class="p">{</span></div><div class='line' id='LC307'>&nbsp;&nbsp;<span class="n">ILboolean</span> <span class="n">success</span><span class="p">;</span></div><div class='line' id='LC308'><br/></div><div class='line' id='LC309'>&nbsp;&nbsp;<span class="cm">/* initialization of DevIL */</span></div><div class='line' id='LC310'>&nbsp;&nbsp;<span class="n">ilInit</span><span class="p">();</span></div><div class='line' id='LC311'><br/></div><div class='line' id='LC312'>&nbsp;&nbsp;<span class="cm">/* scan scene&#39;s materials for textures */</span></div><div class='line' id='LC313'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">m</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">m</span><span class="o">&lt;</span><span class="n">scene</span><span class="o">-&gt;</span><span class="n">mNumMaterials</span><span class="p">;</span> <span class="o">++</span><span class="n">m</span><span class="p">)</span>   <span class="p">{</span></div><div class='line' id='LC314'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">texIndex</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC315'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiString</span> <span class="n">path</span><span class="p">;</span></div><div class='line' id='LC316'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiReturn</span> <span class="n">texFound</span> <span class="o">=</span> <span class="n">scene</span><span class="o">-&gt;</span><span class="n">mMaterials</span><span class="p">[</span><span class="n">m</span><span class="p">]</span><span class="o">-&gt;</span><span class="n">GetTexture</span><span class="p">(</span><span class="n">aiTextureType_DIFFUSE</span><span class="p">,</span> <span class="n">texIndex</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">path</span><span class="p">);</span></div><div class='line' id='LC317'><br/></div><div class='line' id='LC318'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">while</span> <span class="p">(</span><span class="n">texFound</span> <span class="o">==</span> <span class="n">AI_SUCCESS</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC319'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//fill map with textures, OpenGL image ids set to 0</span></div><div class='line' id='LC320'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">textureIdMap</span><span class="p">[</span><span class="n">path</span><span class="p">.</span><span class="n">data</span><span class="p">]</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC321'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// more textures?</span></div><div class='line' id='LC322'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">texIndex</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC323'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">texFound</span> <span class="o">=</span> <span class="n">scene</span><span class="o">-&gt;</span><span class="n">mMaterials</span><span class="p">[</span><span class="n">m</span><span class="p">]</span><span class="o">-&gt;</span><span class="n">GetTexture</span><span class="p">(</span><span class="n">aiTextureType_DIFFUSE</span><span class="p">,</span> <span class="n">texIndex</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">path</span><span class="p">);</span></div><div class='line' id='LC324'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC325'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC326'><br/></div><div class='line' id='LC327'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">numTextures</span> <span class="o">=</span> <span class="n">textureIdMap</span><span class="p">.</span><span class="n">size</span><span class="p">();</span></div><div class='line' id='LC328'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer : loaded &quot;</span> <span class="o">&lt;&lt;</span> <span class="n">numTextures</span> <span class="o">&lt;&lt;</span> <span class="s">&quot; textures.&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC329'><br/></div><div class='line' id='LC330'>&nbsp;&nbsp;<span class="cm">/* create and fill array with DevIL texture ids */</span></div><div class='line' id='LC331'>&nbsp;&nbsp;<span class="n">ILuint</span><span class="o">*</span> <span class="n">imageIds</span> <span class="o">=</span> <span class="k">new</span> <span class="n">ILuint</span><span class="p">[</span><span class="n">numTextures</span><span class="p">];</span></div><div class='line' id='LC332'>&nbsp;&nbsp;<span class="n">ilGenImages</span><span class="p">(</span><span class="n">numTextures</span><span class="p">,</span> <span class="n">imageIds</span><span class="p">);</span></div><div class='line' id='LC333'><br/></div><div class='line' id='LC334'>&nbsp;&nbsp;<span class="cm">/* create and fill array with GL texture ids */</span></div><div class='line' id='LC335'>&nbsp;&nbsp;<span class="n">GLuint</span><span class="o">*</span> <span class="n">textureIds</span> <span class="o">=</span> <span class="k">new</span> <span class="n">GLuint</span><span class="p">[</span><span class="n">numTextures</span><span class="p">];</span></div><div class='line' id='LC336'>&nbsp;&nbsp;<span class="n">glGenTextures</span><span class="p">(</span><span class="n">numTextures</span><span class="p">,</span> <span class="n">textureIds</span><span class="p">);</span> <span class="cm">/* Texture name generation */</span></div><div class='line' id='LC337'><br/></div><div class='line' id='LC338'>&nbsp;&nbsp;<span class="cm">/* get iterator */</span></div><div class='line' id='LC339'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">map</span><span class="o">&lt;</span><span class="n">std</span><span class="o">::</span><span class="n">string</span><span class="p">,</span> <span class="n">GLuint</span><span class="o">&gt;::</span><span class="n">iterator</span> <span class="n">itr</span> <span class="o">=</span> <span class="n">textureIdMap</span><span class="p">.</span><span class="n">begin</span><span class="p">();</span></div><div class='line' id='LC340'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">i</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC341'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(;</span> <span class="n">itr</span> <span class="o">!=</span> <span class="n">textureIdMap</span><span class="p">.</span><span class="n">end</span><span class="p">();</span> <span class="o">++</span><span class="n">i</span><span class="p">,</span> <span class="o">++</span><span class="n">itr</span><span class="p">)</span></div><div class='line' id='LC342'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC343'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">//save IL image ID</span></div><div class='line' id='LC344'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">filename</span> <span class="o">=</span> <span class="p">(</span><span class="o">*</span><span class="n">itr</span><span class="p">).</span><span class="n">first</span><span class="p">;</span>  <span class="c1">// get filename</span></div><div class='line' id='LC345'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">(</span><span class="o">*</span><span class="n">itr</span><span class="p">).</span><span class="n">second</span> <span class="o">=</span> <span class="n">textureIds</span><span class="p">[</span><span class="n">i</span><span class="p">];</span>        <span class="c1">// save texture id for filename in map</span></div><div class='line' id='LC346'><br/></div><div class='line' id='LC347'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ilBindImage</span><span class="p">(</span><span class="n">imageIds</span><span class="p">[</span><span class="n">i</span><span class="p">]);</span> <span class="cm">/* Binding of DevIL image name */</span></div><div class='line' id='LC348'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ilEnable</span><span class="p">(</span><span class="n">IL_ORIGIN_SET</span><span class="p">);</span></div><div class='line' id='LC349'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ilOriginFunc</span><span class="p">(</span><span class="n">IL_ORIGIN_LOWER_LEFT</span><span class="p">);</span></div><div class='line' id='LC350'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">success</span> <span class="o">=</span> <span class="n">ilLoadImage</span><span class="p">((</span><span class="n">ILstring</span><span class="p">)</span><span class="n">filename</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></div><div class='line' id='LC351'><br/></div><div class='line' id='LC352'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">success</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC353'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/* Convert image to RGBA */</span></div><div class='line' id='LC354'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ilConvertImage</span><span class="p">(</span><span class="n">IL_RGBA</span><span class="p">,</span> <span class="n">IL_UNSIGNED_BYTE</span><span class="p">);</span></div><div class='line' id='LC355'><br/></div><div class='line' id='LC356'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cm">/* Create and load textures to OpenGL */</span></div><div class='line' id='LC357'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindTexture</span><span class="p">(</span><span class="n">GL_TEXTURE_2D</span><span class="p">,</span> <span class="n">textureIds</span><span class="p">[</span><span class="n">i</span><span class="p">]);</span></div><div class='line' id='LC358'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glTexParameteri</span><span class="p">(</span><span class="n">GL_TEXTURE_2D</span><span class="p">,</span> <span class="n">GL_TEXTURE_MAG_FILTER</span><span class="p">,</span> <span class="n">GL_LINEAR</span><span class="p">);</span></div><div class='line' id='LC359'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glTexParameteri</span><span class="p">(</span><span class="n">GL_TEXTURE_2D</span><span class="p">,</span> <span class="n">GL_TEXTURE_MIN_FILTER</span><span class="p">,</span> <span class="n">GL_LINEAR</span><span class="p">);</span></div><div class='line' id='LC360'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glTexImage2D</span><span class="p">(</span><span class="n">GL_TEXTURE_2D</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">GL_RGBA</span><span class="p">,</span> <span class="n">ilGetInteger</span><span class="p">(</span><span class="n">IL_IMAGE_WIDTH</span><span class="p">),</span></div><div class='line' id='LC361'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ilGetInteger</span><span class="p">(</span><span class="n">IL_IMAGE_HEIGHT</span><span class="p">),</span> <span class="mi">0</span><span class="p">,</span> <span class="n">GL_RGBA</span><span class="p">,</span> <span class="n">GL_UNSIGNED_BYTE</span><span class="p">,</span></div><div class='line' id='LC362'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ilGetData</span><span class="p">());</span></div><div class='line' id='LC363'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC364'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">else</span></div><div class='line' id='LC365'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span><span class="s">&quot;Couldn&#39;t load Image: %s</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span> <span class="n">filename</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></div><div class='line' id='LC366'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC367'>&nbsp;&nbsp;<span class="cm">/* Because we have already copied image data into texture data</span></div><div class='line' id='LC368'><span class="cm">    we can release memory used by image. */</span></div><div class='line' id='LC369'>&nbsp;&nbsp;<span class="n">ilDeleteImages</span><span class="p">(</span><span class="n">numTextures</span><span class="p">,</span> <span class="n">imageIds</span><span class="p">);</span></div><div class='line' id='LC370'><br/></div><div class='line' id='LC371'>&nbsp;&nbsp;<span class="c1">//Cleanup</span></div><div class='line' id='LC372'>&nbsp;&nbsp;<span class="k">delete</span> <span class="p">[]</span> <span class="n">imageIds</span><span class="p">;</span></div><div class='line' id='LC373'>&nbsp;&nbsp;<span class="k">delete</span> <span class="p">[]</span> <span class="n">textureIds</span><span class="p">;</span></div><div class='line' id='LC374'><br/></div><div class='line' id='LC375'>&nbsp;&nbsp;<span class="c1">//return success;</span></div><div class='line' id='LC376'>&nbsp;&nbsp;<span class="k">return</span> <span class="nb">true</span><span class="p">;</span></div><div class='line' id='LC377'><span class="p">}</span></div><div class='line' id='LC378'><br/></div><div class='line' id='LC379'><span class="c1">// Handle the matrix stack (modelview)</span></div><div class='line' id='LC380'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">pushMatrix</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC381'>&nbsp;&nbsp;<span class="kt">float</span> <span class="o">*</span><span class="n">aux</span> <span class="o">=</span> <span class="p">(</span><span class="kt">float</span> <span class="o">*</span><span class="p">)</span><span class="n">malloc</span><span class="p">(</span><span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span> <span class="o">*</span> <span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC382'>&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">aux</span><span class="p">,</span> <span class="n">modelMatrix</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span> <span class="o">*</span> <span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC383'>&nbsp;&nbsp;<span class="n">matrixStack</span><span class="p">.</span><span class="n">push_back</span><span class="p">(</span><span class="n">aux</span><span class="p">);</span></div><div class='line' id='LC384'><span class="p">}</span></div><div class='line' id='LC385'><br/></div><div class='line' id='LC386'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">popMatrix</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC387'>&nbsp;&nbsp;<span class="kt">float</span> <span class="o">*</span><span class="n">m</span> <span class="o">=</span> <span class="n">matrixStack</span><span class="p">[</span><span class="n">matrixStack</span><span class="p">.</span><span class="n">size</span><span class="p">()</span><span class="o">-</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC388'>&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">modelMatrix</span><span class="p">,</span> <span class="n">m</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span> <span class="o">*</span> <span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC389'>&nbsp;&nbsp;<span class="n">matrixStack</span><span class="p">.</span><span class="n">pop_back</span><span class="p">();</span></div><div class='line' id='LC390'>&nbsp;&nbsp;<span class="n">free</span><span class="p">(</span><span class="n">m</span><span class="p">);</span></div><div class='line' id='LC391'><span class="p">}</span></div><div class='line' id='LC392'><br/></div><div class='line' id='LC393'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">setIdentityMatrix</span><span class="p">(</span> <span class="kt">float</span> <span class="o">*</span><span class="n">mat</span><span class="p">,</span></div><div class='line' id='LC394'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">size</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC395'>&nbsp;&nbsp;<span class="c1">// fill matrix with 0s</span></div><div class='line' id='LC396'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">size</span> <span class="o">*</span> <span class="n">size</span><span class="p">;</span> <span class="o">++</span><span class="n">i</span><span class="p">)</span></div><div class='line' id='LC397'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC398'><br/></div><div class='line' id='LC399'>&nbsp;&nbsp;<span class="c1">// fill diagonal with 1s</span></div><div class='line' id='LC400'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="n">size</span><span class="p">;</span> <span class="o">++</span><span class="n">i</span><span class="p">)</span></div><div class='line' id='LC401'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="n">i</span> <span class="o">+</span> <span class="n">i</span> <span class="o">*</span> <span class="n">size</span><span class="p">]</span> <span class="o">=</span> <span class="mf">1.0f</span><span class="p">;</span></div><div class='line' id='LC402'><span class="p">}</span></div><div class='line' id='LC403'><br/></div><div class='line' id='LC404'><span class="c1">// Defines a transformation matrix mat with a translation</span></div><div class='line' id='LC405'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">setTranslationMatrix</span><span class="p">(</span><span class="kt">float</span> <span class="o">*</span><span class="n">mat</span><span class="p">,</span></div><div class='line' id='LC406'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">x</span><span class="p">,</span></div><div class='line' id='LC407'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">y</span><span class="p">,</span></div><div class='line' id='LC408'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">z</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC409'>&nbsp;&nbsp;<span class="n">setIdentityMatrix</span><span class="p">(</span><span class="n">mat</span><span class="p">,</span><span class="mi">4</span><span class="p">);</span></div><div class='line' id='LC410'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span> <span class="o">=</span> <span class="n">x</span><span class="p">;</span></div><div class='line' id='LC411'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">13</span><span class="p">]</span> <span class="o">=</span> <span class="n">y</span><span class="p">;</span></div><div class='line' id='LC412'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">14</span><span class="p">]</span> <span class="o">=</span> <span class="n">z</span><span class="p">;</span></div><div class='line' id='LC413'><span class="p">}</span></div><div class='line' id='LC414'><br/></div><div class='line' id='LC415'><span class="c1">// Defines a transformation matrix mat with a scale</span></div><div class='line' id='LC416'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">setScaleMatrix</span><span class="p">(</span><span class="kt">float</span> <span class="o">*</span><span class="n">mat</span><span class="p">,</span></div><div class='line' id='LC417'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">sx</span><span class="p">,</span></div><div class='line' id='LC418'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">sy</span><span class="p">,</span></div><div class='line' id='LC419'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">sz</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC420'>&nbsp;&nbsp;<span class="n">setIdentityMatrix</span><span class="p">(</span><span class="n">mat</span><span class="p">,</span><span class="mi">4</span><span class="p">);</span></div><div class='line' id='LC421'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="n">sx</span><span class="p">;</span></div><div class='line' id='LC422'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">5</span><span class="p">]</span> <span class="o">=</span> <span class="n">sy</span><span class="p">;</span></div><div class='line' id='LC423'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">10</span><span class="p">]</span> <span class="o">=</span> <span class="n">sz</span><span class="p">;</span></div><div class='line' id='LC424'><span class="p">}</span></div><div class='line' id='LC425'><br/></div><div class='line' id='LC426'><span class="c1">// Defines a transformation matrix mat with a rotation</span></div><div class='line' id='LC427'><span class="c1">// angle alpha and a rotation axis (x,y,z)</span></div><div class='line' id='LC428'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">setRotationMatrix</span><span class="p">(</span><span class="kt">float</span> <span class="o">*</span><span class="n">mat</span><span class="p">,</span> <span class="kt">float</span> <span class="n">angle</span><span class="p">,</span></div><div class='line' id='LC429'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">x</span><span class="p">,</span> <span class="kt">float</span> <span class="n">y</span><span class="p">,</span> <span class="kt">float</span> <span class="n">z</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC430'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">radAngle</span> <span class="o">=</span> <span class="n">DegToRad</span><span class="p">(</span><span class="n">angle</span><span class="p">);</span></div><div class='line' id='LC431'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">co</span> <span class="o">=</span> <span class="n">cos</span><span class="p">(</span><span class="n">radAngle</span><span class="p">);</span></div><div class='line' id='LC432'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">si</span> <span class="o">=</span> <span class="n">sin</span><span class="p">(</span><span class="n">radAngle</span><span class="p">);</span></div><div class='line' id='LC433'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">x2</span> <span class="o">=</span> <span class="n">x</span><span class="o">*</span><span class="n">x</span><span class="p">;</span></div><div class='line' id='LC434'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">y2</span> <span class="o">=</span> <span class="n">y</span><span class="o">*</span><span class="n">y</span><span class="p">;</span></div><div class='line' id='LC435'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">z2</span> <span class="o">=</span> <span class="n">z</span><span class="o">*</span><span class="n">z</span><span class="p">;</span></div><div class='line' id='LC436'><br/></div><div class='line' id='LC437'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="n">x2</span> <span class="o">+</span> <span class="p">(</span><span class="n">y2</span> <span class="o">+</span> <span class="n">z2</span><span class="p">)</span> <span class="o">*</span> <span class="n">co</span><span class="p">;</span></div><div class='line' id='LC438'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">4</span><span class="p">]</span> <span class="o">=</span> <span class="n">x</span> <span class="o">*</span> <span class="n">y</span> <span class="o">*</span> <span class="p">(</span><span class="mi">1</span> <span class="o">-</span> <span class="n">co</span><span class="p">)</span> <span class="o">-</span> <span class="n">z</span> <span class="o">*</span> <span class="n">si</span><span class="p">;</span></div><div class='line' id='LC439'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">8</span><span class="p">]</span> <span class="o">=</span> <span class="n">x</span> <span class="o">*</span> <span class="n">z</span> <span class="o">*</span> <span class="p">(</span><span class="mi">1</span> <span class="o">-</span> <span class="n">co</span><span class="p">)</span> <span class="o">+</span> <span class="n">y</span> <span class="o">*</span> <span class="n">si</span><span class="p">;</span></div><div class='line' id='LC440'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span><span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC441'><br/></div><div class='line' id='LC442'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">x</span> <span class="o">*</span> <span class="n">y</span> <span class="o">*</span> <span class="p">(</span><span class="mi">1</span> <span class="o">-</span> <span class="n">co</span><span class="p">)</span> <span class="o">+</span> <span class="n">z</span> <span class="o">*</span> <span class="n">si</span><span class="p">;</span></div><div class='line' id='LC443'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">5</span><span class="p">]</span> <span class="o">=</span> <span class="n">y2</span> <span class="o">+</span> <span class="p">(</span><span class="n">x2</span> <span class="o">+</span> <span class="n">z2</span><span class="p">)</span> <span class="o">*</span> <span class="n">co</span><span class="p">;</span></div><div class='line' id='LC444'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">9</span><span class="p">]</span> <span class="o">=</span> <span class="n">y</span> <span class="o">*</span> <span class="n">z</span> <span class="o">*</span> <span class="p">(</span><span class="mi">1</span> <span class="o">-</span> <span class="n">co</span><span class="p">)</span> <span class="o">-</span> <span class="n">x</span> <span class="o">*</span> <span class="n">si</span><span class="p">;</span></div><div class='line' id='LC445'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">13</span><span class="p">]</span><span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC446'><br/></div><div class='line' id='LC447'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">=</span> <span class="n">x</span> <span class="o">*</span> <span class="n">z</span> <span class="o">*</span> <span class="p">(</span><span class="mi">1</span> <span class="o">-</span> <span class="n">co</span><span class="p">)</span> <span class="o">-</span> <span class="n">y</span> <span class="o">*</span> <span class="n">si</span><span class="p">;</span></div><div class='line' id='LC448'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">6</span><span class="p">]</span> <span class="o">=</span> <span class="n">y</span> <span class="o">*</span> <span class="n">z</span> <span class="o">*</span> <span class="p">(</span><span class="mi">1</span> <span class="o">-</span> <span class="n">co</span><span class="p">)</span> <span class="o">+</span> <span class="n">x</span> <span class="o">*</span> <span class="n">si</span><span class="p">;</span></div><div class='line' id='LC449'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">10</span><span class="p">]</span><span class="o">=</span> <span class="n">z2</span> <span class="o">+</span> <span class="p">(</span><span class="n">x2</span> <span class="o">+</span> <span class="n">y2</span><span class="p">)</span> <span class="o">*</span> <span class="n">co</span><span class="p">;</span></div><div class='line' id='LC450'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">14</span><span class="p">]</span><span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC451'><br/></div><div class='line' id='LC452'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">3</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC453'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">7</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC454'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">11</span><span class="p">]</span><span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC455'>&nbsp;&nbsp;<span class="n">mat</span><span class="p">[</span><span class="mi">15</span><span class="p">]</span><span class="o">=</span> <span class="mf">1.0f</span><span class="p">;</span></div><div class='line' id='LC456'><span class="p">}</span></div><div class='line' id='LC457'><br/></div><div class='line' id='LC458'><span class="c1">// Render Assimp Model</span></div><div class='line' id='LC459'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">recursiveRender</span> <span class="p">(</span><span class="k">const</span> <span class="n">aiScene</span> <span class="o">*</span><span class="n">sc</span><span class="p">,</span></div><div class='line' id='LC460'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="n">aiNode</span><span class="o">*</span> <span class="n">nd</span><span class="p">)</span></div><div class='line' id='LC461'><span class="p">{</span></div><div class='line' id='LC462'>&nbsp;&nbsp;<span class="c1">// Get node transformation matrix</span></div><div class='line' id='LC463'>&nbsp;&nbsp;<span class="n">aiMatrix4x4</span> <span class="n">m</span> <span class="o">=</span> <span class="n">nd</span><span class="o">-&gt;</span><span class="n">mTransformation</span><span class="p">;</span></div><div class='line' id='LC464'><br/></div><div class='line' id='LC465'>&nbsp;&nbsp;<span class="n">m</span><span class="p">.</span><span class="n">Transpose</span><span class="p">();</span>    <span class="c1">// OpenGL matrices are column major</span></div><div class='line' id='LC466'>&nbsp;&nbsp;<span class="n">pushMatrix</span><span class="p">();</span>     <span class="c1">// save model matrix and apply node transformation</span></div><div class='line' id='LC467'><br/></div><div class='line' id='LC468'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">aux</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC469'>&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">aux</span><span class="p">,</span><span class="o">&amp;</span><span class="n">m</span><span class="p">,</span><span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">)</span> <span class="o">*</span> <span class="mi">16</span><span class="p">);</span></div><div class='line' id='LC470'>&nbsp;&nbsp;<span class="n">multMatrix</span><span class="p">(</span><span class="n">modelMatrix</span><span class="p">,</span> <span class="n">aux</span><span class="p">);</span></div><div class='line' id='LC471'>&nbsp;&nbsp;<span class="n">setModelMatrix</span><span class="p">();</span></div><div class='line' id='LC472'><br/></div><div class='line' id='LC473'><br/></div><div class='line' id='LC474'>&nbsp;&nbsp;<span class="c1">// Draw all meshes assigned to this node</span></div><div class='line' id='LC475'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">n</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">n</span> <span class="o">&lt;</span> <span class="n">nd</span><span class="o">-&gt;</span><span class="n">mNumMeshes</span><span class="p">;</span> <span class="o">++</span><span class="n">n</span><span class="p">){</span></div><div class='line' id='LC476'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Bind material uniform</span></div><div class='line' id='LC477'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindBufferRange</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">materialUniLoc</span><span class="p">,</span></div><div class='line' id='LC478'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">myMeshes</span><span class="p">[</span><span class="n">nd</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">n</span><span class="p">]].</span><span class="n">uniformBlockIndex</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="k">sizeof</span><span class="p">(</span><span class="k">struct</span> <span class="n">MyMaterial</span><span class="p">));</span></div><div class='line' id='LC479'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Bind texture</span></div><div class='line' id='LC480'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindTexture</span><span class="p">(</span><span class="n">GL_TEXTURE_2D</span><span class="p">,</span> <span class="n">myMeshes</span><span class="p">[</span><span class="n">nd</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">n</span><span class="p">]].</span><span class="n">texIndex</span><span class="p">);</span></div><div class='line' id='LC481'><br/></div><div class='line' id='LC482'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Bind VAO</span></div><div class='line' id='LC483'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glBindVertexArray</span><span class="p">(</span><span class="n">myMeshes</span><span class="p">[</span><span class="n">nd</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">n</span><span class="p">]].</span><span class="n">vao</span><span class="p">);</span></div><div class='line' id='LC484'><br/></div><div class='line' id='LC485'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="c1">// Draw</span></div><div class='line' id='LC486'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glDrawElements</span><span class="p">(</span><span class="n">GL_TRIANGLES</span><span class="p">,</span><span class="n">myMeshes</span><span class="p">[</span><span class="n">nd</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">n</span><span class="p">]].</span><span class="n">numFaces</span><span class="o">*</span><span class="mi">3</span><span class="p">,</span><span class="n">GL_UNSIGNED_INT</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC487'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC488'><br/></div><div class='line' id='LC489'>&nbsp;&nbsp;<span class="c1">// draw all children</span></div><div class='line' id='LC490'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">n</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span> <span class="n">n</span> <span class="o">&lt;</span> <span class="n">nd</span><span class="o">-&gt;</span><span class="n">mNumChildren</span><span class="p">;</span> <span class="o">++</span><span class="n">n</span><span class="p">){</span></div><div class='line' id='LC491'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">recursiveRender</span><span class="p">(</span><span class="n">sc</span><span class="p">,</span> <span class="n">nd</span><span class="o">-&gt;</span><span class="n">mChildren</span><span class="p">[</span><span class="n">n</span><span class="p">]);</span></div><div class='line' id='LC492'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC493'>&nbsp;&nbsp;<span class="n">popMatrix</span><span class="p">();</span></div><div class='line' id='LC494'><span class="p">}</span></div><div class='line' id='LC495'><br/></div><div class='line' id='LC496'><br/></div><div class='line' id='LC497'><span class="c1">// Rendering Callback Function</span></div><div class='line' id='LC498'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">renderScene</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC499'><br/></div><div class='line' id='LC500'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">step</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC501'><br/></div><div class='line' id='LC502'>&nbsp;&nbsp;<span class="n">glClear</span><span class="p">(</span><span class="n">GL_COLOR_BUFFER_BIT</span> <span class="o">|</span> <span class="n">GL_DEPTH_BUFFER_BIT</span><span class="p">);</span></div><div class='line' id='LC503'><br/></div><div class='line' id='LC504'>&nbsp;&nbsp;<span class="c1">// set camera matrix</span></div><div class='line' id='LC505'>&nbsp;&nbsp;<span class="n">setCamera</span><span class="p">(</span><span class="n">camX</span><span class="p">,</span><span class="n">camY</span><span class="p">,</span><span class="n">camZ</span><span class="p">,</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC506'><br/></div><div class='line' id='LC507'>&nbsp;&nbsp;<span class="c1">// set the model matrix to the identity Matrix</span></div><div class='line' id='LC508'>&nbsp;&nbsp;<span class="n">setIdentityMatrix</span><span class="p">(</span><span class="n">modelMatrix</span><span class="p">,</span><span class="mi">4</span><span class="p">);</span></div><div class='line' id='LC509'><br/></div><div class='line' id='LC510'>&nbsp;&nbsp;<span class="c1">// sets the model matrix to a scale matrix so that the model fits in the window</span></div><div class='line' id='LC511'>&nbsp;&nbsp;<span class="n">scale</span><span class="p">(</span><span class="n">scaleFactor</span><span class="p">,</span> <span class="n">scaleFactor</span><span class="p">,</span> <span class="n">scaleFactor</span><span class="p">);</span></div><div class='line' id='LC512'><br/></div><div class='line' id='LC513'>&nbsp;&nbsp;<span class="c1">// keep rotating the model</span></div><div class='line' id='LC514'>&nbsp;&nbsp;<span class="n">rotate</span><span class="p">(</span><span class="n">step</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">,</span> <span class="mf">1.0f</span><span class="p">,</span> <span class="mf">0.0f</span><span class="p">);</span></div><div class='line' id='LC515'><br/></div><div class='line' id='LC516'>&nbsp;&nbsp;<span class="c1">// use our shader</span></div><div class='line' id='LC517'>&nbsp;&nbsp;<span class="n">glUseProgram</span><span class="p">(</span><span class="n">program</span><span class="p">);</span></div><div class='line' id='LC518'><br/></div><div class='line' id='LC519'>&nbsp;&nbsp;<span class="c1">// we are only going to use texture unit 0</span></div><div class='line' id='LC520'>&nbsp;&nbsp;<span class="c1">// unfortunately samplers can&#39;t reside in uniform blocks</span></div><div class='line' id='LC521'>&nbsp;&nbsp;<span class="c1">// so we have set this uniform separately</span></div><div class='line' id='LC522'>&nbsp;&nbsp;<span class="n">glUniform1i</span><span class="p">(</span><span class="n">texUnit</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC523'><br/></div><div class='line' id='LC524'>&nbsp;&nbsp;<span class="n">recursiveRender</span><span class="p">(</span><span class="n">scene</span><span class="p">,</span> <span class="n">scene</span><span class="o">-&gt;</span><span class="n">mRootNode</span><span class="p">);</span></div><div class='line' id='LC525'><br/></div><div class='line' id='LC526'>&nbsp;&nbsp;<span class="c1">// FPS computation and display</span></div><div class='line' id='LC527'>&nbsp;&nbsp;<span class="n">frame</span><span class="o">++</span><span class="p">;</span></div><div class='line' id='LC528'>&nbsp;&nbsp;<span class="n">time</span><span class="o">=</span><span class="n">glutGet</span><span class="p">(</span><span class="n">GLUT_ELAPSED_TIME</span><span class="p">);</span></div><div class='line' id='LC529'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">time</span> <span class="o">-</span> <span class="n">timebase</span> <span class="o">&gt;</span> <span class="mi">1000</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC530'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">sprintf</span><span class="p">(</span><span class="n">s</span><span class="p">,</span><span class="s">&quot;FPS:%4.2f&quot;</span><span class="p">,</span></div><div class='line' id='LC531'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">frame</span><span class="o">*</span><span class="mf">1000.0</span><span class="o">/</span><span class="p">(</span><span class="n">time</span><span class="o">-</span><span class="n">timebase</span><span class="p">));</span></div><div class='line' id='LC532'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">timebase</span> <span class="o">=</span> <span class="n">time</span><span class="p">;</span></div><div class='line' id='LC533'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">frame</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC534'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glutSetWindowTitle</span><span class="p">(</span><span class="n">s</span><span class="p">);</span></div><div class='line' id='LC535'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC536'><br/></div><div class='line' id='LC537'>&nbsp;&nbsp;<span class="c1">// swap buffers</span></div><div class='line' id='LC538'>&nbsp;&nbsp;<span class="n">glutSwapBuffers</span><span class="p">();</span></div><div class='line' id='LC539'><span class="p">}</span></div><div class='line' id='LC540'><br/></div><div class='line' id='LC541'><span class="cm">/*</span></div><div class='line' id='LC542'><span class="cm"> * WARNING : This opengl rendering stack crushes previous definitions of :</span></div><div class='line' id='LC543'><span class="cm"> * - model view</span></div><div class='line' id='LC544'><span class="cm"> * - projection matrix</span></div><div class='line' id='LC545'><span class="cm"> * - camera matrix</span></div><div class='line' id='LC546'><span class="cm"> */</span></div><div class='line' id='LC547'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">renderSceneToFB</span><span class="p">(</span><span class="k">const</span> <span class="kt">float</span> <span class="o">*</span><span class="n">camera_pose</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC548'><br/></div><div class='line' id='LC549'>&nbsp;&nbsp;<span class="n">glEnable</span><span class="p">(</span><span class="n">GL_DEPTH_TEST</span><span class="p">);</span></div><div class='line' id='LC550'>&nbsp;&nbsp;<span class="n">glEnable</span><span class="p">(</span><span class="n">GL_CULL_FACE</span><span class="p">);</span></div><div class='line' id='LC551'><br/></div><div class='line' id='LC552'>&nbsp;&nbsp;<span class="c1">// Set up the camera position, &#39;old style&#39;</span></div><div class='line' id='LC553'>&nbsp;&nbsp;<span class="n">glMatrixMode</span><span class="p">(</span><span class="n">GL_MODELVIEW</span><span class="p">);</span></div><div class='line' id='LC554'>&nbsp;&nbsp;<span class="n">glLoadIdentity</span><span class="p">();</span></div><div class='line' id='LC555'>&nbsp;&nbsp;<span class="n">glTranslatef</span><span class="p">(</span><span class="o">-</span><span class="n">camera_pose</span><span class="p">[</span><span class="mi">0</span><span class="p">],</span> <span class="o">-</span><span class="n">camera_pose</span><span class="p">[</span><span class="mi">1</span><span class="p">],</span> <span class="o">-</span><span class="n">camera_pose</span><span class="p">[</span><span class="mi">2</span><span class="p">]);</span></div><div class='line' id='LC556'>&nbsp;&nbsp;<span class="n">glScalef</span><span class="p">(</span><span class="n">scaleFactor</span><span class="p">,</span> <span class="n">scaleFactor</span><span class="p">,</span> <span class="n">scaleFactor</span><span class="p">);</span></div><div class='line' id='LC557'>&nbsp;&nbsp;<span class="n">glRotatef</span><span class="p">(</span><span class="mf">90.f</span><span class="p">,</span> <span class="mf">1.0</span><span class="p">,</span> <span class="mf">0.0</span><span class="p">,</span> <span class="mf">0.0</span><span class="p">);</span></div><div class='line' id='LC558'>&nbsp;&nbsp;<span class="n">glRotatef</span><span class="p">(</span><span class="mf">180.f</span><span class="p">,</span> <span class="mf">0.0</span><span class="p">,</span> <span class="mf">1.0</span><span class="p">,</span> <span class="mf">0.0</span><span class="p">);</span></div><div class='line' id='LC559'><br/></div><div class='line' id='LC560'>&nbsp;&nbsp;<span class="c1">// FIXME : Still an issue with the translation of the modelview (?)</span></div><div class='line' id='LC561'>&nbsp;&nbsp;<span class="n">glGetFloatv</span><span class="p">(</span><span class="n">GL_MODELVIEW_MATRIX</span><span class="p">,</span> <span class="n">modelMatrix</span><span class="p">);</span></div><div class='line' id='LC562'>&nbsp;&nbsp;<span class="n">pushMatrix</span><span class="p">();</span></div><div class='line' id='LC563'>&nbsp;&nbsp;<span class="n">setModelMatrix</span><span class="p">();</span></div><div class='line' id='LC564'><br/></div><div class='line' id='LC565'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">pm</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC566'>&nbsp;&nbsp;<span class="n">glGetFloatv</span><span class="p">(</span><span class="n">GL_PROJECTION_MATRIX</span><span class="p">,</span> <span class="n">pm</span><span class="p">);</span></div><div class='line' id='LC567'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC568'>&nbsp;&nbsp;<span class="n">glBufferSubData</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">ProjMatrixOffset</span><span class="p">,</span> <span class="n">MatrixSize</span><span class="p">,</span> <span class="n">pm</span><span class="p">);</span></div><div class='line' id='LC569'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC570'><br/></div><div class='line' id='LC571'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">vm</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC572'>&nbsp;&nbsp;<span class="n">setIdentityMatrix</span><span class="p">(</span><span class="n">vm</span><span class="p">,</span><span class="mi">4</span><span class="p">);</span></div><div class='line' id='LC573'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC574'>&nbsp;&nbsp;<span class="n">glBufferSubData</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">ViewMatrixOffset</span><span class="p">,</span> <span class="n">MatrixSize</span><span class="p">,</span> <span class="n">vm</span><span class="p">);</span></div><div class='line' id='LC575'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC576'><br/></div><div class='line' id='LC577'>&nbsp;&nbsp;<span class="c1">// Render all the models&#39; nodes</span></div><div class='line' id='LC578'>&nbsp;&nbsp;<span class="n">glUseProgram</span><span class="p">(</span><span class="n">program</span><span class="p">);</span></div><div class='line' id='LC579'>&nbsp;&nbsp;<span class="n">glUniform1i</span><span class="p">(</span><span class="n">texUnit</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span> <span class="c1">// FIXME: possible issue with the textures, no rendering..</span></div><div class='line' id='LC580'><br/></div><div class='line' id='LC581'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="nb">NULL</span> <span class="o">!=</span> <span class="n">scene</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC582'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">recursiveRender</span><span class="p">(</span><span class="n">scene</span><span class="p">,</span> <span class="n">scene</span><span class="o">-&gt;</span><span class="n">mRootNode</span><span class="p">);</span></div><div class='line' id='LC583'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC584'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer: no model to display&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC585'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC586'><br/></div><div class='line' id='LC587'>&nbsp;&nbsp;<span class="n">glUseProgram</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span>      <span class="c1">// Stop using the shaders</span></div><div class='line' id='LC588'>&nbsp;&nbsp;<span class="n">glBindVertexArray</span><span class="p">(</span><span class="mi">0</span><span class="p">);</span> <span class="c1">// Unbind VBA</span></div><div class='line' id='LC589'><span class="p">}</span></div><div class='line' id='LC590'><br/></div><div class='line' id='LC591'><br/></div><div class='line' id='LC592'><span class="n">GLuint</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">setupShaders</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC593'>&nbsp;&nbsp;<span class="kt">char</span> <span class="o">*</span><span class="n">vs</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">,</span><span class="o">*</span><span class="n">fs</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">,</span><span class="o">*</span><span class="n">fs2</span> <span class="o">=</span> <span class="nb">NULL</span><span class="p">;</span></div><div class='line' id='LC594'><br/></div><div class='line' id='LC595'>&nbsp;&nbsp;<span class="n">GLuint</span> <span class="n">p</span><span class="p">,</span><span class="n">v</span><span class="p">,</span><span class="n">f</span><span class="p">;</span></div><div class='line' id='LC596'><br/></div><div class='line' id='LC597'>&nbsp;&nbsp;<span class="n">v</span> <span class="o">=</span> <span class="n">glCreateShader</span><span class="p">(</span><span class="n">GL_VERTEX_SHADER</span><span class="p">);</span></div><div class='line' id='LC598'>&nbsp;&nbsp;<span class="n">f</span> <span class="o">=</span> <span class="n">glCreateShader</span><span class="p">(</span><span class="n">GL_FRAGMENT_SHADER</span><span class="p">);</span></div><div class='line' id='LC599'><br/></div><div class='line' id='LC600'><span class="c1">//  // TODO: Handle automatically the opengl capabilities of the platform</span></div><div class='line' id='LC601'><span class="c1">//  // OpengGL 2</span></div><div class='line' id='LC602'><span class="c1">//  static const std::string vertexShaderFile = &quot;dirLightAmbDiffSpec.vert&quot;;</span></div><div class='line' id='LC603'><span class="c1">//  static const std::string fragmentShaderFile = &quot;dirLightAmbDiffSpec.frag&quot;;</span></div><div class='line' id='LC604'><span class="c1">//  handle_matrix_stack = false;</span></div><div class='line' id='LC605'><br/></div><div class='line' id='LC606'>&nbsp;&nbsp;<span class="c1">// OpenGL 3,3 and above</span></div><div class='line' id='LC607'>&nbsp;&nbsp;<span class="k">static</span> <span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">vertexShaderFile</span> <span class="o">=</span> <span class="s">&quot;dirlightdiffambpix.vert&quot;</span><span class="p">;</span></div><div class='line' id='LC608'>&nbsp;&nbsp;<span class="k">static</span> <span class="k">const</span> <span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">fragmentShaderFile</span> <span class="o">=</span> <span class="s">&quot;dirlightdiffambpix.frag&quot;</span><span class="p">;</span></div><div class='line' id='LC609'><br/></div><div class='line' id='LC610'><span class="c1">//  // Custom shaders</span></div><div class='line' id='LC611'><span class="c1">//  static const std::string vertexShaderFile = &quot;vertexShader.vert&quot;;</span></div><div class='line' id='LC612'><span class="c1">//  static const std::string fragmentShaderFile = &quot;fragmentShader.frag&quot;;</span></div><div class='line' id='LC613'>&nbsp;&nbsp;<span class="n">handle_matrix_stack</span> <span class="o">=</span> <span class="nb">false</span><span class="p">;</span></div><div class='line' id='LC614'><br/></div><div class='line' id='LC615'>&nbsp;&nbsp;<span class="n">vs</span> <span class="o">=</span> <span class="n">textFileRead</span><span class="p">(</span><span class="n">vertexShaderFile</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></div><div class='line' id='LC616'>&nbsp;&nbsp;<span class="n">fs</span> <span class="o">=</span> <span class="n">textFileRead</span><span class="p">(</span><span class="n">fragmentShaderFile</span><span class="p">.</span><span class="n">c_str</span><span class="p">());</span></div><div class='line' id='LC617'><br/></div><div class='line' id='LC618'>&nbsp;&nbsp;<span class="k">const</span> <span class="kt">char</span> <span class="o">*</span> <span class="n">vv</span> <span class="o">=</span> <span class="n">vs</span><span class="p">;</span></div><div class='line' id='LC619'>&nbsp;&nbsp;<span class="k">const</span> <span class="kt">char</span> <span class="o">*</span> <span class="n">ff</span> <span class="o">=</span> <span class="n">fs</span><span class="p">;</span></div><div class='line' id='LC620'><br/></div><div class='line' id='LC621'>&nbsp;&nbsp;<span class="n">glShaderSource</span><span class="p">(</span><span class="n">v</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">vv</span><span class="p">,</span><span class="nb">NULL</span><span class="p">);</span></div><div class='line' id='LC622'>&nbsp;&nbsp;<span class="n">glShaderSource</span><span class="p">(</span><span class="n">f</span><span class="p">,</span> <span class="mi">1</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">ff</span><span class="p">,</span><span class="nb">NULL</span><span class="p">);</span></div><div class='line' id='LC623'><br/></div><div class='line' id='LC624'>&nbsp;&nbsp;<span class="n">free</span><span class="p">(</span><span class="n">vs</span><span class="p">);</span></div><div class='line' id='LC625'>&nbsp;&nbsp;<span class="n">free</span><span class="p">(</span><span class="n">fs</span><span class="p">);</span></div><div class='line' id='LC626'><br/></div><div class='line' id='LC627'>&nbsp;&nbsp;<span class="n">glCompileShader</span><span class="p">(</span><span class="n">v</span><span class="p">);</span></div><div class='line' id='LC628'>&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="n">title_str</span> <span class="o">=</span> <span class="s">&quot;AssimpRenderer&quot;</span><span class="p">;</span></div><div class='line' id='LC629'>&nbsp;&nbsp;<span class="k">const</span> <span class="kt">char</span> <span class="o">*</span><span class="n">title</span> <span class="o">=</span> <span class="n">title_str</span><span class="p">.</span><span class="n">c_str</span><span class="p">();</span></div><div class='line' id='LC630'>&nbsp;&nbsp;<span class="n">printOglError</span><span class="p">(</span><span class="n">title</span><span class="p">,</span> <span class="mi">711</span><span class="p">);</span></div><div class='line' id='LC631'><br/></div><div class='line' id='LC632'>&nbsp;&nbsp;<span class="n">glCompileShader</span><span class="p">(</span><span class="n">f</span><span class="p">);</span></div><div class='line' id='LC633'>&nbsp;&nbsp;<span class="n">printOglError</span><span class="p">(</span><span class="n">title</span><span class="p">,</span> <span class="mi">714</span><span class="p">);</span></div><div class='line' id='LC634'><br/></div><div class='line' id='LC635'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;Shader info : &quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC636'>&nbsp;&nbsp;<span class="n">printShaderInfoLog</span><span class="p">(</span><span class="n">v</span><span class="p">);</span></div><div class='line' id='LC637'>&nbsp;&nbsp;<span class="n">printShaderInfoLog</span><span class="p">(</span><span class="n">f</span><span class="p">);</span></div><div class='line' id='LC638'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;-----&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC639'><br/></div><div class='line' id='LC640'>&nbsp;&nbsp;<span class="n">p</span> <span class="o">=</span> <span class="n">glCreateProgram</span><span class="p">();</span></div><div class='line' id='LC641'>&nbsp;&nbsp;<span class="n">glAttachShader</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="n">v</span><span class="p">);</span></div><div class='line' id='LC642'>&nbsp;&nbsp;<span class="n">glAttachShader</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="n">f</span><span class="p">);</span></div><div class='line' id='LC643'><br/></div><div class='line' id='LC644'>&nbsp;&nbsp;<span class="n">glBindFragDataLocation</span><span class="p">(</span><span class="n">p</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="s">&quot;output&quot;</span><span class="p">);</span></div><div class='line' id='LC645'><br/></div><div class='line' id='LC646'>&nbsp;&nbsp;<span class="n">glBindAttribLocation</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="n">vertexLoc</span><span class="p">,</span><span class="s">&quot;position&quot;</span><span class="p">);</span></div><div class='line' id='LC647'>&nbsp;&nbsp;<span class="n">glBindAttribLocation</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="n">normalLoc</span><span class="p">,</span><span class="s">&quot;normal&quot;</span><span class="p">);</span></div><div class='line' id='LC648'>&nbsp;&nbsp;<span class="n">glBindAttribLocation</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="n">texCoordLoc</span><span class="p">,</span><span class="s">&quot;texCoord&quot;</span><span class="p">);</span></div><div class='line' id='LC649'><br/></div><div class='line' id='LC650'>&nbsp;&nbsp;<span class="c1">// Bind Material uniform buffer ?</span></div><div class='line' id='LC651'><span class="c1">//  GLint glGetUniformLocation(GLuint program, const char *name);</span></div><div class='line' id='LC652'>&nbsp;&nbsp;<span class="n">glBindAttribLocation</span> <span class="p">(</span><span class="n">p</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="s">&quot;materialUniLoc&quot;</span><span class="p">);</span></div><div class='line' id='LC653'><span class="c1">// DEBUG</span></div><div class='line' id='LC654'><br/></div><div class='line' id='LC655'>&nbsp;&nbsp;<span class="n">glLinkProgram</span><span class="p">(</span><span class="n">p</span><span class="p">);</span></div><div class='line' id='LC656'>&nbsp;&nbsp;<span class="n">glValidateProgram</span><span class="p">(</span><span class="n">p</span><span class="p">);</span></div><div class='line' id='LC657'>&nbsp;&nbsp;<span class="n">printProgramInfoLog</span><span class="p">(</span><span class="n">p</span><span class="p">);</span></div><div class='line' id='LC658'><br/></div><div class='line' id='LC659'>&nbsp;&nbsp;<span class="n">program</span> <span class="o">=</span> <span class="n">p</span><span class="p">;</span></div><div class='line' id='LC660'>&nbsp;&nbsp;<span class="n">vertexShader</span> <span class="o">=</span> <span class="n">v</span><span class="p">;</span></div><div class='line' id='LC661'>&nbsp;&nbsp;<span class="n">fragmentShader</span> <span class="o">=</span> <span class="n">f</span><span class="p">;</span></div><div class='line' id='LC662'><br/></div><div class='line' id='LC663'>&nbsp;&nbsp;<span class="n">GLuint</span> <span class="n">k</span> <span class="o">=</span> <span class="n">glGetUniformBlockIndex</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="s">&quot;Matrices&quot;</span><span class="p">);</span></div><div class='line' id='LC664'>&nbsp;&nbsp;<span class="n">glUniformBlockBinding</span><span class="p">(</span><span class="n">p</span><span class="p">,</span> <span class="n">k</span><span class="p">,</span> <span class="n">matricesUniLoc</span><span class="p">);</span></div><div class='line' id='LC665'>&nbsp;&nbsp;<span class="n">glUniformBlockBinding</span><span class="p">(</span><span class="n">p</span><span class="p">,</span> <span class="n">glGetUniformBlockIndex</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="s">&quot;Material&quot;</span><span class="p">),</span> <span class="n">materialUniLoc</span><span class="p">);</span></div><div class='line' id='LC666'><br/></div><div class='line' id='LC667'>&nbsp;&nbsp;<span class="n">texUnit</span> <span class="o">=</span> <span class="n">glGetUniformLocation</span><span class="p">(</span><span class="n">p</span><span class="p">,</span><span class="s">&quot;texUnit&quot;</span><span class="p">);</span></div><div class='line' id='LC668'><br/></div><div class='line' id='LC669'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer: Shaders loaded&quot;</span>  <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC670'>&nbsp;&nbsp;<span class="k">return</span><span class="p">(</span><span class="n">p</span><span class="p">);</span></div><div class='line' id='LC671'><span class="p">}</span></div><div class='line' id='LC672'><br/></div><div class='line' id='LC673'><span class="c1">// MODEL MATRIX</span></div><div class='line' id='LC674'><span class="c1">//</span></div><div class='line' id='LC675'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">rotate</span><span class="p">(</span><span class="kt">float</span> <span class="n">angle</span><span class="p">,</span> <span class="kt">float</span> <span class="n">x</span><span class="p">,</span> <span class="kt">float</span> <span class="n">y</span><span class="p">,</span> <span class="kt">float</span> <span class="n">z</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC676'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">aux</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC677'>&nbsp;&nbsp;<span class="n">setRotationMatrix</span><span class="p">(</span><span class="n">aux</span><span class="p">,</span><span class="n">angle</span><span class="p">,</span><span class="n">x</span><span class="p">,</span><span class="n">y</span><span class="p">,</span><span class="n">z</span><span class="p">);</span></div><div class='line' id='LC678'>&nbsp;&nbsp;<span class="n">multMatrix</span><span class="p">(</span><span class="n">modelMatrix</span><span class="p">,</span><span class="n">aux</span><span class="p">);</span></div><div class='line' id='LC679'>&nbsp;&nbsp;<span class="n">setModelMatrix</span><span class="p">();</span></div><div class='line' id='LC680'><span class="p">}</span></div><div class='line' id='LC681'><br/></div><div class='line' id='LC682'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">scale</span><span class="p">(</span><span class="kt">float</span> <span class="n">x</span><span class="p">,</span> <span class="kt">float</span> <span class="n">y</span><span class="p">,</span> <span class="kt">float</span> <span class="n">z</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC683'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">aux</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC684'>&nbsp;&nbsp;<span class="n">setScaleMatrix</span><span class="p">(</span><span class="n">aux</span><span class="p">,</span><span class="n">x</span><span class="p">,</span><span class="n">y</span><span class="p">,</span><span class="n">z</span><span class="p">);</span></div><div class='line' id='LC685'>&nbsp;&nbsp;<span class="n">multMatrix</span><span class="p">(</span><span class="n">modelMatrix</span><span class="p">,</span><span class="n">aux</span><span class="p">);</span></div><div class='line' id='LC686'>&nbsp;&nbsp;<span class="n">setModelMatrix</span><span class="p">();</span></div><div class='line' id='LC687'><span class="p">}</span></div><div class='line' id='LC688'><br/></div><div class='line' id='LC689'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">setModelMatrix</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC690'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC691'>&nbsp;&nbsp;<span class="n">glBufferSubData</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span></div><div class='line' id='LC692'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">ModelMatrixOffset</span><span class="p">,</span> <span class="n">MatrixSize</span><span class="p">,</span> <span class="n">modelMatrix</span><span class="p">);</span></div><div class='line' id='LC693'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC694'><span class="p">}</span></div><div class='line' id='LC695'><br/></div><div class='line' id='LC696'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">setCamera</span><span class="p">(</span><span class="kt">float</span> <span class="n">posX</span><span class="p">,</span> <span class="kt">float</span> <span class="n">posY</span><span class="p">,</span> <span class="kt">float</span> <span class="n">posZ</span><span class="p">,</span></div><div class='line' id='LC697'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">lookAtX</span><span class="p">,</span> <span class="kt">float</span> <span class="n">lookAtY</span><span class="p">,</span> <span class="kt">float</span> <span class="n">lookAtZ</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC698'><br/></div><div class='line' id='LC699'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">dir</span><span class="p">[</span><span class="mi">3</span><span class="p">],</span> <span class="n">right</span><span class="p">[</span><span class="mi">3</span><span class="p">],</span> <span class="n">up</span><span class="p">[</span><span class="mi">3</span><span class="p">];</span></div><div class='line' id='LC700'><br/></div><div class='line' id='LC701'>&nbsp;&nbsp;<span class="n">up</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span>	<span class="n">up</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="mf">1.0f</span><span class="p">;</span>	<span class="n">up</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC702'><br/></div><div class='line' id='LC703'>&nbsp;&nbsp;<span class="n">dir</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span>  <span class="p">(</span><span class="n">lookAtX</span> <span class="o">-</span> <span class="n">posX</span><span class="p">);</span></div><div class='line' id='LC704'>&nbsp;&nbsp;<span class="n">dir</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span>  <span class="p">(</span><span class="n">lookAtY</span> <span class="o">-</span> <span class="n">posY</span><span class="p">);</span></div><div class='line' id='LC705'>&nbsp;&nbsp;<span class="n">dir</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">=</span>  <span class="p">(</span><span class="n">lookAtZ</span> <span class="o">-</span> <span class="n">posZ</span><span class="p">);</span></div><div class='line' id='LC706'>&nbsp;&nbsp;<span class="n">normalize</span><span class="p">(</span><span class="n">dir</span><span class="p">);</span></div><div class='line' id='LC707'><br/></div><div class='line' id='LC708'>&nbsp;&nbsp;<span class="n">crossProduct</span><span class="p">(</span><span class="n">dir</span><span class="p">,</span><span class="n">up</span><span class="p">,</span><span class="n">right</span><span class="p">);</span></div><div class='line' id='LC709'>&nbsp;&nbsp;<span class="n">normalize</span><span class="p">(</span><span class="n">right</span><span class="p">);</span></div><div class='line' id='LC710'><br/></div><div class='line' id='LC711'>&nbsp;&nbsp;<span class="n">crossProduct</span><span class="p">(</span><span class="n">right</span><span class="p">,</span><span class="n">dir</span><span class="p">,</span><span class="n">up</span><span class="p">);</span></div><div class='line' id='LC712'>&nbsp;&nbsp;<span class="n">normalize</span><span class="p">(</span><span class="n">up</span><span class="p">);</span></div><div class='line' id='LC713'><br/></div><div class='line' id='LC714'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">viewMatrix</span><span class="p">[</span><span class="mi">16</span><span class="p">],</span><span class="n">aux</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC715'><br/></div><div class='line' id='LC716'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span>  <span class="o">=</span> <span class="n">right</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC717'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">4</span><span class="p">]</span>  <span class="o">=</span> <span class="n">right</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC718'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">8</span><span class="p">]</span>  <span class="o">=</span> <span class="n">right</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC719'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">12</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC720'><br/></div><div class='line' id='LC721'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span>  <span class="o">=</span> <span class="n">up</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC722'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">5</span><span class="p">]</span>  <span class="o">=</span> <span class="n">up</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC723'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">9</span><span class="p">]</span>  <span class="o">=</span> <span class="n">up</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC724'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">13</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC725'><br/></div><div class='line' id='LC726'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span>  <span class="o">=</span> <span class="o">-</span><span class="n">dir</span><span class="p">[</span><span class="mi">0</span><span class="p">];</span></div><div class='line' id='LC727'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">6</span><span class="p">]</span>  <span class="o">=</span> <span class="o">-</span><span class="n">dir</span><span class="p">[</span><span class="mi">1</span><span class="p">];</span></div><div class='line' id='LC728'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">10</span><span class="p">]</span> <span class="o">=</span> <span class="o">-</span><span class="n">dir</span><span class="p">[</span><span class="mi">2</span><span class="p">];</span></div><div class='line' id='LC729'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">14</span><span class="p">]</span> <span class="o">=</span>  <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC730'><br/></div><div class='line' id='LC731'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">3</span><span class="p">]</span>  <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC732'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">7</span><span class="p">]</span>  <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC733'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">11</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC734'>&nbsp;&nbsp;<span class="n">viewMatrix</span><span class="p">[</span><span class="mi">15</span><span class="p">]</span> <span class="o">=</span> <span class="mf">1.0f</span><span class="p">;</span></div><div class='line' id='LC735'><br/></div><div class='line' id='LC736'>&nbsp;&nbsp;<span class="n">setTranslationMatrix</span><span class="p">(</span><span class="n">aux</span><span class="p">,</span> <span class="o">-</span><span class="n">posX</span><span class="p">,</span> <span class="o">-</span><span class="n">posY</span><span class="p">,</span> <span class="o">-</span><span class="n">posZ</span><span class="p">);</span></div><div class='line' id='LC737'><br/></div><div class='line' id='LC738'>&nbsp;&nbsp;<span class="n">multMatrix</span><span class="p">(</span><span class="n">viewMatrix</span><span class="p">,</span> <span class="n">aux</span><span class="p">);</span></div><div class='line' id='LC739'><br/></div><div class='line' id='LC740'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">matricesUniBuffer</span><span class="p">);</span></div><div class='line' id='LC741'>&nbsp;&nbsp;<span class="n">glBufferSubData</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span> <span class="n">ViewMatrixOffset</span><span class="p">,</span> <span class="n">MatrixSize</span><span class="p">,</span> <span class="n">viewMatrix</span><span class="p">);</span></div><div class='line' id='LC742'>&nbsp;&nbsp;<span class="n">glBindBuffer</span><span class="p">(</span><span class="n">GL_UNIFORM_BUFFER</span><span class="p">,</span><span class="mi">0</span><span class="p">);</span></div><div class='line' id='LC743'><span class="p">}</span></div><div class='line' id='LC744'><br/></div><div class='line' id='LC745'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">translate</span><span class="p">(</span><span class="kt">float</span> <span class="n">x</span><span class="p">,</span> <span class="kt">float</span> <span class="n">y</span><span class="p">,</span> <span class="kt">float</span> <span class="n">z</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC746'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">aux</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC747'>&nbsp;&nbsp;<span class="n">setTranslationMatrix</span><span class="p">(</span><span class="n">aux</span><span class="p">,</span><span class="n">x</span><span class="p">,</span><span class="n">y</span><span class="p">,</span><span class="n">z</span><span class="p">);</span></div><div class='line' id='LC748'>&nbsp;&nbsp;<span class="n">multMatrix</span><span class="p">(</span><span class="n">modelMatrix</span><span class="p">,</span><span class="n">aux</span><span class="p">);</span></div><div class='line' id='LC749'>&nbsp;&nbsp;<span class="n">setModelMatrix</span><span class="p">();</span></div><div class='line' id='LC750'><span class="p">}</span></div><div class='line' id='LC751'><br/></div><div class='line' id='LC752'><span class="c1">// -- Support functions</span></div><div class='line' id='LC753'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">color4_to_float4</span><span class="p">(</span><span class="k">const</span> <span class="n">aiColor4D</span> <span class="o">*</span><span class="n">c</span><span class="p">,</span></div><div class='line' id='LC754'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="n">f</span><span class="p">[</span><span class="mi">4</span><span class="p">])</span> <span class="p">{</span></div><div class='line' id='LC755'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="n">c</span><span class="o">-&gt;</span><span class="n">r</span><span class="p">;</span></div><div class='line' id='LC756'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">c</span><span class="o">-&gt;</span><span class="n">g</span><span class="p">;</span></div><div class='line' id='LC757'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">=</span> <span class="n">c</span><span class="o">-&gt;</span><span class="n">b</span><span class="p">;</span></div><div class='line' id='LC758'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">3</span><span class="p">]</span> <span class="o">=</span> <span class="n">c</span><span class="o">-&gt;</span><span class="n">a</span><span class="p">;</span></div><div class='line' id='LC759'><span class="p">}</span></div><div class='line' id='LC760'><br/></div><div class='line' id='LC761'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">get_bounding_box_for_node</span> <span class="p">(</span><span class="k">const</span> <span class="n">aiNode</span><span class="o">*</span> <span class="n">nd</span><span class="p">,</span></div><div class='line' id='LC762'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiVector3D</span><span class="o">*</span> <span class="n">min</span><span class="p">,</span></div><div class='line' id='LC763'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiVector3D</span><span class="o">*</span> <span class="n">max</span><span class="p">)</span> <span class="k">const</span> <span class="p">{</span></div><div class='line' id='LC764'>&nbsp;&nbsp;<span class="n">aiMatrix4x4</span> <span class="n">prev</span><span class="p">;</span></div><div class='line' id='LC765'>&nbsp;&nbsp;<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">n</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC766'><br/></div><div class='line' id='LC767'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(;</span> <span class="n">n</span> <span class="o">&lt;</span> <span class="n">nd</span><span class="o">-&gt;</span><span class="n">mNumMeshes</span><span class="p">;</span> <span class="o">++</span><span class="n">n</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC768'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">const</span> <span class="n">aiMesh</span><span class="o">*</span> <span class="n">mesh</span> <span class="o">=</span> <span class="n">scene</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">nd</span><span class="o">-&gt;</span><span class="n">mMeshes</span><span class="p">[</span><span class="n">n</span><span class="p">]];</span></div><div class='line' id='LC769'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">t</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">t</span> <span class="o">&lt;</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mNumVertices</span><span class="p">;</span> <span class="o">++</span><span class="n">t</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC770'><br/></div><div class='line' id='LC771'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">aiVector3D</span> <span class="n">tmp</span> <span class="o">=</span> <span class="n">mesh</span><span class="o">-&gt;</span><span class="n">mVertices</span><span class="p">[</span><span class="n">t</span><span class="p">];</span></div><div class='line' id='LC772'><br/></div><div class='line' id='LC773'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">min</span><span class="o">-&gt;</span><span class="n">x</span> <span class="o">=</span> <span class="n">aisgl_min</span><span class="p">(</span><span class="n">min</span><span class="o">-&gt;</span><span class="n">x</span><span class="p">,</span><span class="n">tmp</span><span class="p">.</span><span class="n">x</span><span class="p">);</span></div><div class='line' id='LC774'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">min</span><span class="o">-&gt;</span><span class="n">y</span> <span class="o">=</span> <span class="n">aisgl_min</span><span class="p">(</span><span class="n">min</span><span class="o">-&gt;</span><span class="n">y</span><span class="p">,</span><span class="n">tmp</span><span class="p">.</span><span class="n">y</span><span class="p">);</span></div><div class='line' id='LC775'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">min</span><span class="o">-&gt;</span><span class="n">z</span> <span class="o">=</span> <span class="n">aisgl_min</span><span class="p">(</span><span class="n">min</span><span class="o">-&gt;</span><span class="n">z</span><span class="p">,</span><span class="n">tmp</span><span class="p">.</span><span class="n">z</span><span class="p">);</span></div><div class='line' id='LC776'><br/></div><div class='line' id='LC777'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">max</span><span class="o">-&gt;</span><span class="n">x</span> <span class="o">=</span> <span class="n">aisgl_max</span><span class="p">(</span><span class="n">max</span><span class="o">-&gt;</span><span class="n">x</span><span class="p">,</span><span class="n">tmp</span><span class="p">.</span><span class="n">x</span><span class="p">);</span></div><div class='line' id='LC778'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">max</span><span class="o">-&gt;</span><span class="n">y</span> <span class="o">=</span> <span class="n">aisgl_max</span><span class="p">(</span><span class="n">max</span><span class="o">-&gt;</span><span class="n">y</span><span class="p">,</span><span class="n">tmp</span><span class="p">.</span><span class="n">y</span><span class="p">);</span></div><div class='line' id='LC779'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">max</span><span class="o">-&gt;</span><span class="n">z</span> <span class="o">=</span> <span class="n">aisgl_max</span><span class="p">(</span><span class="n">max</span><span class="o">-&gt;</span><span class="n">z</span><span class="p">,</span><span class="n">tmp</span><span class="p">.</span><span class="n">z</span><span class="p">);</span></div><div class='line' id='LC780'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC781'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC782'><br/></div><div class='line' id='LC783'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="n">n</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">n</span> <span class="o">&lt;</span> <span class="n">nd</span><span class="o">-&gt;</span><span class="n">mNumChildren</span><span class="p">;</span> <span class="o">++</span><span class="n">n</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC784'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">get_bounding_box_for_node</span><span class="p">(</span><span class="n">nd</span><span class="o">-&gt;</span><span class="n">mChildren</span><span class="p">[</span><span class="n">n</span><span class="p">],</span><span class="n">min</span><span class="p">,</span><span class="n">max</span><span class="p">);</span></div><div class='line' id='LC785'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC786'><span class="p">}</span></div><div class='line' id='LC787'><br/></div><div class='line' id='LC788'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">get_bounding_box</span> <span class="p">(</span><span class="n">aiVector3D</span><span class="o">*</span> <span class="n">min</span><span class="p">,</span> <span class="n">aiVector3D</span><span class="o">*</span> <span class="n">max</span><span class="p">)</span> <span class="k">const</span><span class="p">{</span></div><div class='line' id='LC789'>&nbsp;&nbsp;<span class="n">min</span><span class="o">-&gt;</span><span class="n">x</span> <span class="o">=</span> <span class="n">min</span><span class="o">-&gt;</span><span class="n">y</span> <span class="o">=</span> <span class="n">min</span><span class="o">-&gt;</span><span class="n">z</span> <span class="o">=</span>  <span class="mf">1e10</span><span class="n">f</span><span class="p">;</span></div><div class='line' id='LC790'>&nbsp;&nbsp;<span class="n">max</span><span class="o">-&gt;</span><span class="n">x</span> <span class="o">=</span> <span class="n">max</span><span class="o">-&gt;</span><span class="n">y</span> <span class="o">=</span> <span class="n">max</span><span class="o">-&gt;</span><span class="n">z</span> <span class="o">=</span> <span class="o">-</span><span class="mf">1e10</span><span class="n">f</span><span class="p">;</span></div><div class='line' id='LC791'>&nbsp;&nbsp;<span class="n">get_bounding_box_for_node</span><span class="p">(</span><span class="n">scene</span><span class="o">-&gt;</span><span class="n">mRootNode</span><span class="p">,</span><span class="n">min</span><span class="p">,</span><span class="n">max</span><span class="p">);</span></div><div class='line' id='LC792'><span class="p">}</span></div><div class='line' id='LC793'><br/></div><div class='line' id='LC794'><span class="c1">// Not quite optimal... recode with GLM lib ?</span></div><div class='line' id='LC795'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">multMatrix</span><span class="p">(</span><span class="kt">float</span> <span class="o">*</span><span class="n">a</span><span class="p">,</span></div><div class='line' id='LC796'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">float</span> <span class="o">*</span><span class="n">b</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC797'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">res</span><span class="p">[</span><span class="mi">16</span><span class="p">];</span></div><div class='line' id='LC798'>&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">i</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">i</span> <span class="o">&lt;</span> <span class="mi">4</span><span class="p">;</span> <span class="o">++</span><span class="n">i</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC799'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">j</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">j</span> <span class="o">&lt;</span> <span class="mi">4</span><span class="p">;</span> <span class="o">++</span><span class="n">j</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC800'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">res</span><span class="p">[</span><span class="n">j</span><span class="o">*</span><span class="mi">4</span> <span class="o">+</span> <span class="n">i</span><span class="p">]</span> <span class="o">=</span> <span class="mf">0.0f</span><span class="p">;</span></div><div class='line' id='LC801'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">k</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span> <span class="n">k</span> <span class="o">&lt;</span> <span class="mi">4</span><span class="p">;</span> <span class="o">++</span><span class="n">k</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC802'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">res</span><span class="p">[</span><span class="n">j</span><span class="o">*</span><span class="mi">4</span> <span class="o">+</span> <span class="n">i</span><span class="p">]</span> <span class="o">+=</span> <span class="n">a</span><span class="p">[</span><span class="n">k</span><span class="o">*</span><span class="mi">4</span> <span class="o">+</span> <span class="n">i</span><span class="p">]</span> <span class="o">*</span> <span class="n">b</span><span class="p">[</span><span class="n">j</span><span class="o">*</span><span class="mi">4</span> <span class="o">+</span> <span class="n">k</span><span class="p">];</span></div><div class='line' id='LC803'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC804'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC805'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC806'>&nbsp;&nbsp;<span class="n">memcpy</span><span class="p">(</span><span class="n">a</span><span class="p">,</span> <span class="n">res</span><span class="p">,</span> <span class="mi">16</span> <span class="o">*</span> <span class="k">sizeof</span><span class="p">(</span><span class="kt">float</span><span class="p">));</span></div><div class='line' id='LC807'><span class="p">}</span></div><div class='line' id='LC808'><br/></div><div class='line' id='LC809'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">normalize</span><span class="p">(</span><span class="kt">float</span> <span class="o">*</span><span class="n">a</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC810'><br/></div><div class='line' id='LC811'>&nbsp;&nbsp;<span class="kt">float</span> <span class="n">mag</span> <span class="o">=</span> <span class="n">sqrt</span><span class="p">(</span><span class="n">a</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">*</span> <span class="n">a</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span>  <span class="o">+</span>  <span class="n">a</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">*</span> <span class="n">a</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span>  <span class="o">+</span>  <span class="n">a</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">*</span> <span class="n">a</span><span class="p">[</span><span class="mi">2</span><span class="p">]);</span></div><div class='line' id='LC812'><br/></div><div class='line' id='LC813'>&nbsp;&nbsp;<span class="n">a</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">/=</span> <span class="n">mag</span><span class="p">;</span></div><div class='line' id='LC814'>&nbsp;&nbsp;<span class="n">a</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">/=</span> <span class="n">mag</span><span class="p">;</span></div><div class='line' id='LC815'>&nbsp;&nbsp;<span class="n">a</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">/=</span> <span class="n">mag</span><span class="p">;</span></div><div class='line' id='LC816'><span class="p">}</span></div><div class='line' id='LC817'><br/></div><div class='line' id='LC818'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">set_float4</span><span class="p">(</span><span class="kt">float</span> <span class="n">f</span><span class="p">[</span><span class="mi">4</span><span class="p">],</span> <span class="kt">float</span> <span class="n">a</span><span class="p">,</span> <span class="kt">float</span> <span class="n">b</span><span class="p">,</span> <span class="kt">float</span> <span class="n">c</span><span class="p">,</span> <span class="kt">float</span> <span class="n">d</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC819'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">0</span><span class="p">]</span> <span class="o">=</span> <span class="n">a</span><span class="p">;</span></div><div class='line' id='LC820'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">1</span><span class="p">]</span> <span class="o">=</span> <span class="n">b</span><span class="p">;</span></div><div class='line' id='LC821'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">2</span><span class="p">]</span> <span class="o">=</span> <span class="n">c</span><span class="p">;</span></div><div class='line' id='LC822'>&nbsp;&nbsp;<span class="n">f</span><span class="p">[</span><span class="mi">3</span><span class="p">]</span> <span class="o">=</span> <span class="n">d</span><span class="p">;</span></div><div class='line' id='LC823'><span class="p">}</span></div><div class='line' id='LC824'><br/></div><div class='line' id='LC825'><span class="c1">// -- Print logs.. --</span></div><div class='line' id='LC826'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">printShaderInfoLog</span><span class="p">(</span><span class="n">GLuint</span> <span class="n">obj</span><span class="p">)</span></div><div class='line' id='LC827'><span class="p">{</span></div><div class='line' id='LC828'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">infologLength</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">charsWritten</span>  <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC829'>&nbsp;&nbsp;<span class="kt">char</span> <span class="o">*</span><span class="n">infoLog</span><span class="p">;</span></div><div class='line' id='LC830'><br/></div><div class='line' id='LC831'>&nbsp;&nbsp;<span class="n">glGetShaderiv</span><span class="p">(</span><span class="n">obj</span><span class="p">,</span> <span class="n">GL_INFO_LOG_LENGTH</span><span class="p">,</span><span class="o">&amp;</span><span class="n">infologLength</span><span class="p">);</span></div><div class='line' id='LC832'><br/></div><div class='line' id='LC833'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">infologLength</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span>  <span class="p">{</span></div><div class='line' id='LC834'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">infoLog</span> <span class="o">=</span> <span class="p">(</span><span class="kt">char</span> <span class="o">*</span><span class="p">)</span><span class="n">malloc</span><span class="p">(</span><span class="n">infologLength</span><span class="p">);</span></div><div class='line' id='LC835'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGetShaderInfoLog</span><span class="p">(</span><span class="n">obj</span><span class="p">,</span> <span class="n">infologLength</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">charsWritten</span><span class="p">,</span> <span class="n">infoLog</span><span class="p">);</span></div><div class='line' id='LC836'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span><span class="s">&quot;%s</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span><span class="n">infoLog</span><span class="p">);</span></div><div class='line' id='LC837'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">free</span><span class="p">(</span><span class="n">infoLog</span><span class="p">);</span></div><div class='line' id='LC838'>&nbsp;&nbsp;<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC839'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">std</span><span class="o">::</span><span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;AssimpRenderer : Could not load shader&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC840'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC841'><span class="p">}</span></div><div class='line' id='LC842'><br/></div><div class='line' id='LC843'><span class="kt">int</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">printOglError</span><span class="p">(</span><span class="k">const</span> <span class="kt">char</span> <span class="o">*</span><span class="n">file</span><span class="p">,</span></div><div class='line' id='LC844'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="kt">int</span> <span class="n">line</span><span class="p">)</span></div><div class='line' id='LC845'><span class="p">{</span></div><div class='line' id='LC846'>&nbsp;&nbsp;<span class="n">GLenum</span> <span class="n">glErr</span><span class="p">;</span></div><div class='line' id='LC847'>&nbsp;&nbsp;<span class="kt">int</span>    <span class="n">retCode</span> <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC848'><br/></div><div class='line' id='LC849'>&nbsp;&nbsp;<span class="n">glErr</span> <span class="o">=</span> <span class="n">glGetError</span><span class="p">();</span></div><div class='line' id='LC850'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">glErr</span> <span class="o">!=</span> <span class="n">GL_NO_ERROR</span><span class="p">)</span></div><div class='line' id='LC851'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC852'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span><span class="s">&quot;glError in file %s @ line %d: %s</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span></div><div class='line' id='LC853'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">file</span><span class="p">,</span> <span class="n">line</span><span class="p">,</span> <span class="n">gluErrorString</span><span class="p">(</span><span class="n">glErr</span><span class="p">));</span></div><div class='line' id='LC854'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">retCode</span> <span class="o">=</span> <span class="mi">1</span><span class="p">;</span></div><div class='line' id='LC855'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC856'>&nbsp;&nbsp;<span class="k">return</span> <span class="n">retCode</span><span class="p">;</span></div><div class='line' id='LC857'><span class="p">}</span></div><div class='line' id='LC858'><br/></div><div class='line' id='LC859'><span class="kt">void</span> <span class="n">AssimpRenderer</span><span class="o">::</span><span class="n">printProgramInfoLog</span><span class="p">(</span><span class="n">GLuint</span> <span class="n">obj</span><span class="p">)</span></div><div class='line' id='LC860'><span class="p">{</span></div><div class='line' id='LC861'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">infologLength</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="n">charsWritten</span>  <span class="o">=</span> <span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC862'>&nbsp;&nbsp;<span class="kt">char</span> <span class="o">*</span><span class="n">infoLog</span><span class="p">;</span></div><div class='line' id='LC863'><br/></div><div class='line' id='LC864'>&nbsp;&nbsp;<span class="n">glGetProgramiv</span><span class="p">(</span><span class="n">obj</span><span class="p">,</span> <span class="n">GL_INFO_LOG_LENGTH</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">infologLength</span><span class="p">);</span></div><div class='line' id='LC865'><br/></div><div class='line' id='LC866'>&nbsp;&nbsp;<span class="k">if</span> <span class="p">(</span><span class="n">infologLength</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC867'>&nbsp;&nbsp;<span class="p">{</span></div><div class='line' id='LC868'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">infoLog</span> <span class="o">=</span> <span class="p">(</span><span class="kt">char</span> <span class="o">*</span><span class="p">)</span><span class="n">malloc</span><span class="p">(</span><span class="n">infologLength</span><span class="p">);</span></div><div class='line' id='LC869'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">glGetProgramInfoLog</span><span class="p">(</span><span class="n">obj</span><span class="p">,</span> <span class="n">infologLength</span><span class="p">,</span> <span class="o">&amp;</span><span class="n">charsWritten</span><span class="p">,</span> <span class="n">infoLog</span><span class="p">);</span></div><div class='line' id='LC870'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">printf</span><span class="p">(</span><span class="s">&quot;%s</span><span class="se">\n</span><span class="s">&quot;</span><span class="p">,</span><span class="n">infoLog</span><span class="p">);</span></div><div class='line' id='LC871'>&nbsp;&nbsp;&nbsp;&nbsp;<span class="n">free</span><span class="p">(</span><span class="n">infoLog</span><span class="p">);</span></div><div class='line' id='LC872'>&nbsp;&nbsp;<span class="p">}</span></div><div class='line' id='LC873'><span class="p">}</span></div></pre></div></td>
          </tr>
        </table>
  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.19857s from github-fe132-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-remove-close close js-ajax-error-dismiss"></a>
      Something went wrong with that request. Please try again.
    </div>

  </body>
</html>

