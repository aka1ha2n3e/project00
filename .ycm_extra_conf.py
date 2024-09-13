import os
import ycm_core

# プロジェクトのルートディレクトリを検出する関数
def FindProjectRoot(filename):
    current_dir = os.path.dirname(os.path.abspath(filename))
    while current_dir != '/':
        if os.path.exists(os.path.join(current_dir, '*.json')):
            return current_dir
        current_dir = os.path.dirname(current_dir)
    return None

# 補完候補を探すディレクトリ
project_root = FindProjectRoot(__file__)
if project_root:
    compilation_database_folder = project_root
else:
    compilation_database_folder = None

if compilation_database_folder:
    database = ycm_core.CompilationDatabase(compilation_database_folder)
else:
    database = None

def FlagsForFile(filename, **kwargs):
    if database:
        # databaseから補完候補を取得します
        compilation_info = database.GetCompilationInfoForFile(filename)
        final_flags = compilation_info.compiler_flags_
    else:
        # databaseがない場合、デフォルトの補完候補を設定します
        final_flags = [
            '-Wall',
            '-Wextra',
            '-Werror',
            '-std=c++17',
            '-x', 'c++',
            '-I', 'include',
        ]

    return {
        'flags': final_flags,
        'do_cache': True
    }