project('wxbriscola', 'cpp', version: '0.5')
subdir('po')
wx_dep = dependency('wxwidgets', version : '>=3.0.0', required : true)
executable('wxbriscola', ['BriscoApp.cpp','BriscoFrame.cpp','BriscoPanel.cpp', 'carta.cpp', 'CartaAltaFrame.cpp', 'DoubleValidator.cpp', 'elaboratoreCarteBriscola.cpp', 'giocatore.cpp', 'giocatoreHelperCpu.cpp', 'giocatoreHelperUtente.cpp', 'IntValidator.cpp', 'mazzo.cpp', 'OpzioniFrame.cpp'], dependencies : [wx_dep], install: true)

install_data('wxBriscola.png',
             install_dir : '/var/lib/flatpak/exports/share/icons/hicolor/128x128')
install_data('wxBriscola.desktop',
             install_dir : '/var/lib/flatpak/exports/share/applications')


