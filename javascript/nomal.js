// ==UserScript==
// @name         稿定设计去水印1.8
// @namespace    https://greasyfork.org/zh-CN/users/1344035-leng-y
// @version      1.8
// @author       LENG_Y
// @description  2025.01.22最新一键去稿定设计水印的脚本，自用分享。
// @match        https://www.gaoding.com/editor/design?*
// @match        https://www.focodesign.com/editor/design?*
// @match        https://www.focodesign.com/editor/odyssey?template_id=*
// @grant        unsafeWindow
// @downloadURL https://update.greasyfork.org/scripts/502420/%E7%A8%BF%E5%AE%9A%E8%AE%BE%E8%AE%A1%E5%8E%BB%E6%B0%B4%E5%8D%B018.user.js
// @updateURL https://update.greasyfork.org/scripts/502420/%E7%A8%BF%E5%AE%9A%E8%AE%BE%E8%AE%A1%E5%8E%BB%E6%B0%B4%E5%8D%B018.meta.js
// ==/UserScript==

const blockedImageReplacement = 'data:image/webp;base64,UklGRpYAAABXRUJQVlA4WAoAAAAQAAAAAAAAAAAAQUxQSAIAAAAAAFZQOCAYAAAAMAEAnQEqAQABAA/A/iWkAANwAP7lagAAUFNBSU4AAAA4QklNA+0AAAAAABAASAAAAAEAAgBIAAAAAQACOEJJTQQoAAAAAAAMAAAAAj/wAAAAAAAAOEJJTQRDAAAAAAAOUGJlVwEQAAYAAAAAAAA=';

const originalSetSrc = Object.getOwnPropertyDescriptor(HTMLImageElement.prototype, 'src').set;

Object.defineProperty(HTMLImageElement.prototype, 'src', {
    set(value) {
        if (value.startsWith('data:image/svg+xml;base64,Cjxzdmcgd2lkdGg9IjMwMCIgaGVpZ2h0PSIyNTAiIHZpZXdCb3g9IjAgMCAzMDAgMjUwIiBmaWxsPSJub25lIi')) {
            console.log('Intercepted SVG:', value);
            originalSetSrc.call(this, blockedImageReplacement);
            return;
        }
        originalSetSrc.call(this, value);
    },
});

var checkInterval = 800;
var intervalId = setInterval(function () {
    var exportImg = document.querySelector('.dc-header__export-actions');
    if (exportImg) {
        clearInterval(intervalId);

        // 创建“清屏”按钮
        var clearScreenNode = document.createElement("div");
        clearScreenNode.className = "dc-header__clear-screen";
        clearScreenNode.innerHTML = `
      <div style="margin-right: 8px;">
        <div class="gda-btn-group">
          <button type="button" class="download-popover__primary gda-btn gda-btn-secondary clear-screen-btn">
            <span>清屏</span>
          </button>
        </div>
      </div>`;
        exportImg.parentNode.insertBefore(clearScreenNode, exportImg);

        // 添加“清屏”按钮事件
        var clearScreenBtn = document.querySelector('.clear-screen-btn');
        var isHidden = false; // 用于记录隐藏状态
        clearScreenBtn.addEventListener('click', function () {
            var elementsToToggle = [
                ...document.querySelectorAll('.resource-station, .right-panel, .main__bottom, .dui-noob-guide-index')
            ];

            if (!isHidden) {
                // 隐藏指定元素
                elementsToToggle.forEach(element => {
                    if (element) element.style.display = 'none';
                });
                clearScreenBtn.querySelector('span').textContent = '恢复';
            } else {
                // 显示指定元素
                elementsToToggle.forEach(element => {
                    if (element) element.style.display = '';
                });
                clearScreenBtn.querySelector('span').textContent = '清屏';
            }

            isHidden = !isHidden; // 切换状态
        });
    }
}, checkInterval);