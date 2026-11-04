
undefined4 FUN_0059cc80(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  FUN_0059be30((param_3 + param_2 * 4) * 0x140c + 0x14 + param_1,0,param_4,param_5);
  iVar1 = param_2 * 0x100 + 0x2717c + param_1;
  bVar2 = false;
  if (param_4 < param_5 + param_4) {
    iVar4 = param_4;
    do {
      pcVar5 = (char *)(param_3 * 0x100 + param_2 * 0x400 + 0x1e134 + param_1 + iVar4);
      *pcVar5 = '\0';
      uVar3 = param_3;
      if (*(byte *)(iVar4 + iVar1) == param_3) {
        for (; (-1 < (int)uVar3 && (*pcVar5 == '\0')); pcVar5 = pcVar5 + -0x100) {
          uVar3 = uVar3 - 1;
        }
        if (uVar3 == 0xffffffff) {
          *(undefined1 *)(iVar4 + iVar1) = 0xff;
        }
        else {
          *(char *)(iVar4 + iVar1) = (char)uVar3;
          bVar2 = true;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5 + param_4);
    if (bVar2) {
      FUN_0059c860(param_1,param_2,param_4);
    }
  }
  return 0;
}

