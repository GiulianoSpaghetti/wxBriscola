Name:               wxbriscola
Version:            0.3.6
Release:            1%{?dist}
License:            GPLv3+
Group:              Games
Source:             %{name}-%{version}-src.tar.bz2
URL:                http://github.com/numerunix/wxBriscola
BuildRequires:      wxGTK3-devel, meson, ninja-build
Requires:     	    wxGTK3, wxbriscola-i18n, wxbriscola-mazzi-hd-napoletano
Summary:            Il simulatore del gioco della briscola per due giocatori
%description
Il simulatore del gioco della briscola per 2 giocatori.
Manca il multiplayer...

%package mazzi-hd-belle-epoque
Summary: Mazzo belle epoque per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-belle-epoque
Mazzo belle epoque per la wxBriscola e la JBriscola

%package mazzi-hd-bergamasco
Summary: Mazzo bergamasco per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-bergamasco
Mazzo bergamasco per la wxBriscola e la JBriscola

%package mazzi-hd-binario
Summary: Mazzo binario per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-binario
Mazzo binario per la wxBriscola e la JBriscola

%package mazzi-hd-bolognese
Summary: Mazzo bolognese per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-bolognese
Mazzo bolognese per la wxBriscola e la JBriscola

%package mazzi-hd-bresciano
Summary: Mazzo bresciano per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-bresciano
Mazzo bresciano per la wxBriscola e la JBriscola

%package mazzi-hd-dr-francy
Summary: Primo mazzo interamente self made per la wxBriscola e la JBriscola.
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-dr-francy
Primo mazzo interamente self made per la wxBriscola e la JBriscola.
Riprenditi presto Francesca San Severino.

%package mazzi-hd-gatti
Summary: Mazzo di gatti per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-gatti
Secondo mazzo interamente self-made per la wxBriscola e la JBriscola


%package mazzi-hd-genovese
Summary: Mazzo genovese per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-genovese
Mazzo genovese per la wxBriscola e la JBriscola


%package mazzi-hd-lombardo
Summary: Mazzo belle epoque per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-lombardo
Mazzo lombardo per la wxBriscola e la JBriscola


%package mazzi-hd-napoletano
Summary: Mazzo napoletano per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-napoletano
Mazzo napoletano per la wxBriscola e la JBriscola


%package mazzi-hd-piacentino
Summary: Mazzo piacentino per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-piacentino
Mazzo piacentino per la wxBriscola e la JBriscola


%package mazzi-hd-playing-mario
Summary: Mazzo di Mario Bros per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-playing-mario
Mazzo di Mario Bros per la wxBriscola e la JBriscola

%package mazzi-hd-poker-pinup
Summary: Mazzo di belle donne ignude per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-poker-pinup
Mazzo di belle donne ignude per la wxBriscola e la JBriscola


%package mazzi-hd-romagnolo
Summary: Mazzo romagnolo per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-romagnolo
Mazzo romagnolo per la wxBriscola e la JBriscola

%package mazzi-hd-sardo
Summary: Mazzo sardo per la wxBriscola e la JBriscola
Group: Games
BuildArch: noarch
Requires: wxbriscola
%description mazzi-hd-sardo
Mazzo sardo per la wxBriscola e la JBriscola

%package mazzi-hd-siciliano
Summary: Mazzo siciliano per la wxBriscola e la JBriscola
Group: Games
BuildArch: noarch
Requires: wxbriscola
%description mazzi-hd-siciliano
Mazzo siciliano per la wxBriscola e la JBriscola

%package mazzi-hd-toscano
Summary: Mazzo toscano per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-toscano
Mazzo toscano per la wxBriscola e la JBriscola

%package mazzi-hd-trentino
Summary: Mazzo trentino per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-trentino
Mazzo trentino per la wxBriscola e la JBriscola

%package mazzi-hd-trevigiano
Summary: Mazzo trevigiano per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-trevigiano
Mazzo trevigiano per la wxBriscola e la JBriscola


%package mazzi-hd-triestino
Summary: Mazzo triestino per la wxBriscola e la JBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description mazzi-hd-triestino
Mazzo triestino per la wxBriscola e la JBriscola


%package i18n
Summary: File di traduzione linguistica per la wxBriscola
Group: Games
Requires: wxbriscola
BuildArch: noarch
%description i18n
File di traduzione linguistica per la wxBriscola

%prep
%autosetup -n %{name}

%build
%meson
%meson_build

%install
%meson_install

%files
%{_bindir}/wxbriscola
%{_datadir}/applications/wxBriscola.desktop
%{_datadir}/icons/wxBriscola.ico


%files mazzi-hd-belle-epoque
%{_datadir}/wxBriscola/Mazzi/Belle_Epoque

%files mazzi-hd-bergamasco
%{_datadir}/wxBriscola/Mazzi/Bergamasco

%files mazzi-hd-binario
%{_datadir}/wxBriscola/Mazzi/Binario

%files mazzi-hd-bolognese
%{_datadir}/wxBriscola/Mazzi/Bolognese

%files mazzi-hd-bresciano
%{_datadir}/wxBriscola/Mazzi/Bresciano

%files mazzi-hd-dr-francy
%{_datadir}/wxBriscola/Mazzi/Dr_Francy

%files mazzi-hd-gatti
%{_datadir}/wxBriscola/Mazzi/Gatti

%files mazzi-hd-genovese
%{_datadir}/wxBriscola/Mazzi/Genovese

%files mazzi-hd-lombardo
%{_datadir}/wxBriscola/Mazzi/Lombardo

%files mazzi-hd-napoletano
%{_datadir}/wxBriscola/Mazzi/Napoletano

%files mazzi-hd-piacentino
%{_datadir}/wxBriscola/Mazzi/Piacentino

%files mazzi-hd-playing-mario
%{_datadir}/wxBriscola/Mazzi/Playing_Mario

%files mazzi-hd-poker-pinup
%{_datadir}/wxBriscola/Mazzi/Poker_PinUp

%files mazzi-hd-romagnolo
%{_datadir}/wxBriscola/Mazzi/Romagnolo

%files mazzi-hd-sardo
%{_datadir}/wxBriscola/Mazzi/Sardo

%files mazzi-hd-siciliano
%{_datadir}/wxBriscola/Mazzi/Siciliano

%files mazzi-hd-toscano
%{_datadir}/wxBriscola/Mazzi/Toscano

%files mazzi-hd-trentino
%{_datadir}/wxBriscola/Mazzi/Trentino

%files mazzi-hd-trevigiano
%{_datadir}/wxBriscola/Mazzi/Trevigiano

%files mazzi-hd-triestino
%{_datadir}/wxBriscola/Mazzi/Triestino

%files i18n
%{_datadir}/locale/*


%changelog

* Fri Nov 27 2020 Giulio Sorrentino <gsorre84@gmail.com> 0.3.6-1
- Initial release (#00000)
