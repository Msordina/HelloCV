# HelloCV
我是一个说明怎么配置的文件（ ᗜ ‸ ᗜ ）
适用于Ubuntu22.04


项目结构
HelloCV/
|————README.md
|————note cite


环境配置步骤

  git
    直接在终端进行安装指令：
      sudo apt update
      sudo apt install git
      git --version
    安装完毕，配置个人信息：
      git config --global user.name "用户名"
      git config --global user.email "完整邮箱"
    一些鬼知道什么时候会用上的可选项，我建议装上：
      设置默认编辑器
        git config --global core.editor vim
      设置换行符处理
        git config --global core.autocrlf input
      设置推送行为
        git config --global push.default simple
      启用颜色输出
        git config --global color.ui auto
    接下来是非常重要的SSH密钥
      ssh-keygen -t ed25519 -C "完整邮箱"
    代理，启动！
      eval "$(ssh-agent -s)"
      ssh-add ~/.ssh/id_ed25519
    然后从文件管理了里把公钥内容复制一下，注意有pub后缀的那个才是公钥，位置在/.ssh/下
    添加到github的公钥设置中，这方面github有非常显眼的引导
    最后测试一下
      ssh -T git@github.com

  ROS2
    首先你得有一间客房（启用仓库）
      sudo apt install software-properties-common
      sudo add-apt-repository universe
    然后再给客人发邀请函，这里为了能顺利请到客人而不是被墙拦住，我们找一位清华的客人（下载镜像源）
      sudo curl -sSL https://mirrors.tuna.tsinghua.edu.cn/rosdistro/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
    注意不要打错，最好直接启用Xshell复制粘贴
    然后请客人进来（源）
      echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] https://mirrors.tuna.tsinghua.edu.cn/ros2/ubuntu jammy main" | sudo tee /etc/apt/sources.list.d/ros2.list
    嗯，现在收拾一下沙发（更新软件列表）
      sudo apt update
    请客人坐下（正式安装）
      sudo apt install ros-humble-desktop
    一个好的待客之道（设置环境变量）
      echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
      source ~/.bashrc
    现在已经安装完成了，用这个指令来查看一些基础信息：
      ros2 doctor
    出现一些警告是正常的，只是一些内容的提醒更新而已，可以自行解决，这里搁置。

  OpenCV 4.5.4（基础版，根据需求选择，可跳过本段并在【综合配置】中安装完整版）
      sudo apt install -y python3-pip
      pip3 install --upgrade pip
      pip install opencv-python
    简单的指令，平平淡淡才是真，借助pip安装
    验证安装
      python3 -c "import cv2; print('OpenCV 安装成功! 版本:', cv2.__version__)"

  VS Code
    通过snap安装
      sudo snap install --classic code
    安装一堆乱七八糟的扩展，它们没有多少内存，但缺了就会很麻烦
      code --install-extension ms-python.python
      code --install-extension ms-python.vscode-pylance
      code --install-extension ms-python.black-formatter
      code --install-extension ms-python.isort
      code --install-extension ms-vscode.cpptools
      code --install-extension formulahendry.auto-rename-tag
      code --install-extension christian-kohler.path-intellisense
      code --install-extension pkief.material-icon-theme
      code --install-extension zhuangtongfa.material-theme
      code --install-extension eamodio.gitlens
      code --install-extension ms-vscode-remote.vscode-remote-extensionpack
    闭着眼睛输就完啦#摊手
    接下来打开VS Code
    输入Ctrl+，（这里有三个键喔，逗号也是键）
    搜索以下内容并修改：
      python.defaultInterpreterPath → /usr/bin/python3
      python.analysis.autoImportCompletions → ✓ 勾选
      python.analysis.typeCheckingMode → basic
      editor.insertSpaces → ✓ 勾选
      editor.formatOnSave → ✓ 勾选
      editor.formatOnPaste → ✓ 勾选
      files.autoSave → afterDelay

  接下来是真正的大boss辣：综合配置
    首先更新系统，打磨工具，准备迎战：
      sudo apt update && sudo apt upgrade -y
      sudo apt install -y build-essential cmake git curl wget
      sudo apt install -y python3-pip python3-venv python3-dev
    然后是py开发（是python！不要做奇怪的联想！）环境
      创建
      cd ~/dev_workspace
      python3 -m venv venv
      激活
      source venv/bin/activate
      安装
      pip install --upgrade pip
      pip install numpy matplotlib jupyter ipykernel pillow
      pip install opencv-contrib-python
      pip install black pylint autopep8
      添加虚拟环境
      python -m ipykernel install --user --name=dev_workspace --display-name="Python (Dev Workspace)"
    完善VS Code配置
      cd ~/dev_workspace
      mkdir -p .vscode
      cat > .vscode/settings.json << 'EOF'
      {
    "python.defaultInterpreterPath": "${workspaceFolder}/venv/bin/python",
    "editor.fontSize": 14,
    "editor.tabSize": 4,
    "editor.formatOnSave": true,
    "files.autoSave": "afterDelay",
    "terminal.integrated.defaultProfile.linux": "bash"
    }
    EOF
     mkdir -p opencv_projects/{src,data}
   创建一下测试功能
     cat > test_environment.py << 'EOF'
     import cv2
     import numpy as np
     import sys
     print("=== 环境快速验证 ===")
     print(f"Python: {sys.version}")
     print(f"OpenCV: {cv2.__version__}")
     img = np.ones((100, 100, 3), dtype=np.uint8) * 255
     gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
     print(f"图像处理测试: {img.shape} -> {gray.shape}")
     print("✅ 环境验证通过！")
     EOF
   激活
     cd ~/dev_workspace
     source venv/bin/activate
     python test_environment.py
     python opencv_projects/src/quick_demo.py
完成！Congratulations！


使用方法
git clone git@github.com:Msordina/HelloCV.git
按照上述环境配置步骤配置环境。
感谢观看






ξ( ✿＞◡❛)
