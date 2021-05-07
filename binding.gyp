{
    'variables': {
        'platform': '<(OS)',
    },
    'conditions': [
        ['platform == "mac"', {'variables': {'platform': 'darwin'}}],
        ['platform == "win"', {'variables': {'platform': 'win32'}}],
    ],
    'targets': [
        {
            'target_name': 'glut',
            'defines': [
                'VERSION=0.4.6',
            ],
            'sources': [
                'src/bindings.cpp',
                'src/electron-glut.cpp'
            ],
            'include_dirs': [
                "<!(node -e \"require('nan')\")",
                '<(module_root_dir)/lib/freeglut/include/GL',
                '<(module_root_dir)/lib/stb',
                '<(module_root_dir)/lib/glfw/include/'
            ],
            'conditions': [
                ['OS=="win"', {
                    'library_dirs': [
                        '<(module_root_dir)/lib/freeglut/lib/x64',
                        '<(module_root_dir)/lib/glfw/lib-vc2017'
                    ],
                    'libraries': [
                        'freeglut.lib',
                        'glfw3dll.lib',
                        'opengl32.lib'
                    ],
                    'defines': ['WIN32_LEAN_AND_MEAN', 'VC_EXTRALEAN', 'NOMINMAX'],
                    'msvs_settings': {
                        'VCCLCompilerTool': {
                            'AdditionalOptions': ['/Oy','/GL','/GF','/Gm-','/EHsc','/MT','/GS','/Gy','/GR-','/Gd'],
                        },
                        'VCLinkerTool': {
                            'AdditionalOptions': ['/OPT:REF','/OPT:ICF','/LTCG', '/NODEFAULTLIB:glfw3.lib'],
                        },
                    },
                    'copies': [
                        {
                            'destination': '<(module_root_dir)/build/Release',
                            'files': [
                                '<(module_root_dir)/lib/freeglut/bin/x64/freeglut.dll',
                                '<(module_root_dir)/lib/glfw/lib-vc2017/glfw3.dll'
                            ]
                        }
                    ]
                }]
            ]
        }
    ]
}