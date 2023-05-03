project('wxbriscola', 'cpp', version: '0.5')
subdir('po')
wx_dep = dependency('wxwidgets', version : '>=3.0.0', required : true)
executable('org.altervista.numerone.wxBriscola', ['BriscoApp.cpp','BriscoFrame.cpp','BriscoPanel.cpp', 'carta.cpp', 'CartaAltaFrame.cpp', 'DoubleValidator.cpp', 'elaboratoreCarteBriscola.cpp', 'giocatore.cpp', 'giocatoreHelperCpu.cpp', 'giocatoreHelperUtente.cpp', 'IntValidator.cpp', 'mazzo.cpp', 'OpzioniFrame.cpp'], dependencies : [wx_dep], install: true)
fs = import('fs')

config_dir = fs.expanduser('~/.local/share/')

install_subdir('assets', install_dir: config_dir)
install_data('org.altervista.numerone.wxBriscola.png',
             install_dir : join_paths(config_dir, 'icons/'))
install_data('org.altervista.numerone.wxBriscola.desktop',
             install_dir : join_paths(config_dir, 'applications'))


