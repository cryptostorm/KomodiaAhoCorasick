

cc_library(
    name = 'SuffixTrie',
    srcs = 'SuffixTrie.cpp',
    extra_cppflags = [ 
        '-Wall',
        # '-Werror',
        # '-Wextra',
        # '-DHAVE_SYS_SYSCALL_H',
    ]
)


cc_binary(
	target_bases = [ 'Projects'],
	name = 'TestAhoCorasik',
	srcs = [
		'TestAhoCorasik.cpp',
		'SuffixTrie.cpp',
	],
	deps = [
        ':SuffixTrie',
	],
	export_incs = ['.',],
	extra_cppflags = [ 
		'-Wall',
		#'-Werror',
		'-Wextra',
	]
)
