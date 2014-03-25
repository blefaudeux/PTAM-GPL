




<!DOCTYPE html>
<html class="  ">
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    
    
    <title>PTAM-GPL/libPTAM/src/VideoSource_Linux_V4L.cc at master · blefaudeux/PTAM-GPL</title>
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
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="614C6E22:75FE:2219847:5331BED6" name="octolytics-dimension-request_id" /><meta content="3072861" name="octolytics-actor-id" /><meta content="blefaudeux" name="octolytics-actor-login" /><meta content="95129eadec7e451a911117456005505a2166509347848ba2482e6f233d247636" name="octolytics-actor-hash" />
    

    
    
    <link rel="icon" type="image/x-icon" href="https://github.global.ssl.fastly.net/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="tE+izvxnmy3Bhtk+h//vlHT5F7r/fPOzxEtPGy0HZkI=" name="csrf-token" />

    <link href="https://github.global.ssl.fastly.net/assets/github-2714be798e3a1abfcbd49ca563fdfa1c177cd2e9.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://github.global.ssl.fastly.net/assets/github2-11ee1161f68234125b5e8198b6c00e0409587b77.css" media="all" rel="stylesheet" type="text/css" />
    


        <script crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/frameworks-1eb4805d296158ea875ffc5fa959a11f5a3cdf13.js" type="text/javascript"></script>
        <script async="async" crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/github-0eb4075decc9810b544396b3366e14fecf793432.js" type="text/javascript"></script>
        
        
      <meta http-equiv="x-pjax-version" content="ec5d8630b4ee3231236cfa8bf8abbf04">

        <link data-pjax-transient rel='permalink' href='/blefaudeux/PTAM-GPL/blob/3d151f95af628523af8492c4a6eca85d0207540d/libPTAM/src/VideoSource_Linux_V4L.cc'>

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
          


<!-- blob contrib key: blob_contributors:v21:36888b8499719c24f56d4ab23f8b62fd -->

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
              <a href="/blefaudeux/PTAM-GPL/blob/Linuxmint15/libPTAM/src/VideoSource_Linux_V4L.cc"
                 data-name="Linuxmint15"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="Linuxmint15">Linuxmint15</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/blefaudeux/PTAM-GPL/blob/load_custom_3d_model/libPTAM/src/VideoSource_Linux_V4L.cc"
                 data-name="load_custom_3d_model"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="load_custom_3d_model">load_custom_3d_model</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/blefaudeux/PTAM-GPL/blob/master/libPTAM/src/VideoSource_Linux_V4L.cc"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/blefaudeux/PTAM-GPL/blob/unified_build/libPTAM/src/VideoSource_Linux_V4L.cc"
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
            <input type="hidden" name="path" id="path" value="libPTAM/src/VideoSource_Linux_V4L.cc" />
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
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/blefaudeux/PTAM-GPL" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">PTAM-GPL</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/blefaudeux/PTAM-GPL/tree/master/libPTAM" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">libPTAM</span></a></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/blefaudeux/PTAM-GPL/tree/master/libPTAM/src" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">src</span></a></span><span class="separator"> / </span><strong class="final-path">VideoSource_Linux_V4L.cc</strong> <span aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="libPTAM/src/VideoSource_Linux_V4L.cc" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


  <div class="commit commit-loader file-history-tease js-deferred-content" data-url="/blefaudeux/PTAM-GPL/contributors/master/libPTAM/src/VideoSource_Linux_V4L.cc">
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
          <span>37 lines (32 sloc)</span>
          <span class="meta-divider"></span>
        <span>1.164 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
                <a class="minibutton js-update-url-with-hash"
                   href="/blefaudeux/PTAM-GPL/edit/master/libPTAM/src/VideoSource_Linux_V4L.cc"
                   data-method="post" rel="nofollow" data-hotkey="e">Edit</a>
          <a href="/blefaudeux/PTAM-GPL/raw/master/libPTAM/src/VideoSource_Linux_V4L.cc" class="button minibutton " id="raw-url">Raw</a>
            <a href="/blefaudeux/PTAM-GPL/blame/master/libPTAM/src/VideoSource_Linux_V4L.cc" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/blefaudeux/PTAM-GPL/commits/master/libPTAM/src/VideoSource_Linux_V4L.cc" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->

            <a class="minibutton danger empty-icon"
               href="/blefaudeux/PTAM-GPL/delete/master/libPTAM/src/VideoSource_Linux_V4L.cc"
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

            </td>
            <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="c1">// Copyright 2008 Isis Innovation Limited</span></div><div class='line' id='LC2'><span class="cp">#include &quot;VideoSource.h&quot;</span></div><div class='line' id='LC3'><span class="cp">#include &lt;cvd/Linux/v4lbuffer.h&gt;</span></div><div class='line' id='LC4'><span class="cp">#include &lt;cvd/colourspace_convert.h&gt;</span></div><div class='line' id='LC5'><span class="cp">#include &lt;cvd/colourspaces.h&gt;</span></div><div class='line' id='LC6'><span class="cp">#include &lt;gvars3/instances.h&gt;</span></div><div class='line' id='LC7'><br/></div><div class='line' id='LC8'><span class="k">using</span> <span class="k">namespace</span> <span class="n">CVD</span><span class="p">;</span></div><div class='line' id='LC9'><span class="k">using</span> <span class="k">namespace</span> <span class="n">std</span><span class="p">;</span></div><div class='line' id='LC10'><span class="k">using</span> <span class="k">namespace</span> <span class="n">GVars3</span><span class="p">;</span></div><div class='line' id='LC11'><br/></div><div class='line' id='LC12'><span class="n">VideoSource</span><span class="o">::</span><span class="n">VideoSource</span><span class="p">()</span></div><div class='line' id='LC13'><span class="p">{</span></div><div class='line' id='LC14'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;  VideoSource_Linux: Opening video source...&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC15'>&nbsp;&nbsp;<span class="n">string</span> <span class="n">QuickCamFile</span> <span class="o">=</span> <span class="n">GV3</span><span class="o">::</span><span class="n">get</span><span class="o">&lt;</span><span class="n">string</span><span class="o">&gt;</span><span class="p">(</span><span class="s">&quot;VideoSource.V4LDevice&quot;</span><span class="p">,</span> <span class="s">&quot;/dev/video0&quot;</span><span class="p">);</span> <span class="c1">//TODO: properly handle the video source</span></div><div class='line' id='LC16'>&nbsp;&nbsp;<span class="n">ImageRef</span> <span class="n">irSize</span> <span class="o">=</span> <span class="n">GV3</span><span class="o">::</span><span class="n">get</span><span class="o">&lt;</span><span class="n">ImageRef</span><span class="o">&gt;</span><span class="p">(</span><span class="s">&quot;VideoSource.Resolution&quot;</span><span class="p">,</span> <span class="n">ImageRef</span><span class="p">(</span><span class="mi">1280</span><span class="p">,</span><span class="mi">720</span><span class="p">));</span></div><div class='line' id='LC17'>&nbsp;&nbsp;<span class="kt">int</span> <span class="n">nFrameRate</span> <span class="o">=</span> <span class="n">GV3</span><span class="o">::</span><span class="n">get</span><span class="o">&lt;</span><span class="kt">int</span><span class="o">&gt;</span><span class="p">(</span><span class="s">&quot;VideoSource.Framerate&quot;</span><span class="p">,</span> <span class="mi">30</span><span class="p">);</span></div><div class='line' id='LC18'>&nbsp;&nbsp;<span class="n">V4LBuffer</span><span class="o">&lt;</span><span class="n">yuv422</span><span class="o">&gt;*</span> <span class="n">pvb</span> <span class="o">=</span> <span class="k">new</span> <span class="n">V4LBuffer</span><span class="o">&lt;</span><span class="n">yuv422</span><span class="o">&gt;</span><span class="p">(</span><span class="n">QuickCamFile</span><span class="p">,</span> <span class="n">irSize</span><span class="p">,</span> <span class="o">-</span><span class="mi">1</span><span class="p">,</span> <span class="nb">false</span><span class="p">,</span> <span class="n">nFrameRate</span><span class="p">);</span></div><div class='line' id='LC19'>&nbsp;&nbsp;<span class="n">mirSize</span> <span class="o">=</span> <span class="n">pvb</span><span class="o">-&gt;</span><span class="n">size</span><span class="p">();</span></div><div class='line' id='LC20'>&nbsp;&nbsp;<span class="n">mptr</span> <span class="o">=</span> <span class="n">pvb</span><span class="p">;</span></div><div class='line' id='LC21'>&nbsp;&nbsp;<span class="n">cout</span> <span class="o">&lt;&lt;</span> <span class="s">&quot;  ... got video source.&quot;</span> <span class="o">&lt;&lt;</span> <span class="n">endl</span><span class="p">;</span></div><div class='line' id='LC22'><span class="p">}</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'><span class="n">ImageRef</span> <span class="n">VideoSource</span><span class="o">::</span><span class="n">Size</span><span class="p">()</span></div><div class='line' id='LC25'><span class="p">{</span> </div><div class='line' id='LC26'>&nbsp;&nbsp;<span class="k">return</span> <span class="n">mirSize</span><span class="p">;</span></div><div class='line' id='LC27'><span class="p">}</span></div><div class='line' id='LC28'><br/></div><div class='line' id='LC29'><span class="kt">void</span> <span class="n">VideoSource</span><span class="o">::</span><span class="n">GetAndFillFrameBWandRGB</span><span class="p">(</span><span class="n">Image</span><span class="o">&lt;</span><span class="n">byte</span><span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">imBW</span><span class="p">,</span> <span class="n">Image</span><span class="o">&lt;</span><span class="n">Rgb</span><span class="o">&lt;</span><span class="n">byte</span><span class="o">&gt;</span> <span class="o">&gt;</span> <span class="o">&amp;</span><span class="n">imRGB</span><span class="p">)</span></div><div class='line' id='LC30'><span class="p">{</span></div><div class='line' id='LC31'>&nbsp;&nbsp;<span class="n">V4LBuffer</span><span class="o">&lt;</span><span class="n">yuv422</span><span class="o">&gt;*</span> <span class="n">pvb</span> <span class="o">=</span> <span class="p">(</span><span class="n">V4LBuffer</span><span class="o">&lt;</span><span class="n">yuv422</span><span class="o">&gt;*</span><span class="p">)</span> <span class="n">mptr</span><span class="p">;</span></div><div class='line' id='LC32'>&nbsp;&nbsp;<span class="n">VideoFrame</span><span class="o">&lt;</span><span class="n">yuv422</span><span class="o">&gt;</span> <span class="o">*</span><span class="n">pVidFrame</span> <span class="o">=</span> <span class="n">pvb</span><span class="o">-&gt;</span><span class="n">get_frame</span><span class="p">();</span></div><div class='line' id='LC33'>&nbsp;&nbsp;<span class="n">convert_image</span><span class="p">(</span><span class="o">*</span><span class="n">pVidFrame</span><span class="p">,</span> <span class="n">imBW</span><span class="p">);</span></div><div class='line' id='LC34'>&nbsp;&nbsp;<span class="n">convert_image</span><span class="p">(</span><span class="o">*</span><span class="n">pVidFrame</span><span class="p">,</span> <span class="n">imRGB</span><span class="p">);</span></div><div class='line' id='LC35'>&nbsp;&nbsp;<span class="n">pvb</span><span class="o">-&gt;</span><span class="n">put_frame</span><span class="p">(</span><span class="n">pVidFrame</span><span class="p">);</span></div><div class='line' id='LC36'><span class="p">}</span></div></pre></div></td>
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
      <li>&copy; 2014 <span title="0.06150s from github-fe132-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
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

