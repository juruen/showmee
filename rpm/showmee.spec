# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.21
# 
# >> macros
# << macros

Name:       showmee
Summary:    PDF Presentation Viewer
Version:    0.0.1
Release:    1
Group:      Development/Tools
License:    LGPLv2.1
URL:        http://www,warp.es
Source0:    %{name}-%{version}.tar.bz2
Source100:  showmee.yaml
BuildRequires:  pkgconfig(QtCore) >= 4.6.0
BuildRequires:  pkgconfig(QtOpenGL)
BuildRequires:  pkgconfig(QtGui)
BuildRequires:  pkgconfig(poppler-qt4)
BuildRequires:  desktop-file-utils


%description
PDF Presentation Viewer



%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
# >> build pre
export PATH=/usr/lib/qt4/bin:$PATH
qmake PREFIX=%{_prefix}
# << build pre



# >> build post
# << build post
%install
rm -rf %{buildroot}
# >> install pre
# << install pre

# >> install post
make INSTALL_ROOT=%{buildroot}/usr install
# << install post
desktop-file-install --delete-original       \
  --dir %{buildroot}%{_datadir}/applications             \
   %{buildroot}%{_datadir}/applications/*.desktop






%files
%defattr(-,root,root,-)
%{_bindir}/showmee
%{_datadir}/applications/*.desktop
# >> files
# << files

