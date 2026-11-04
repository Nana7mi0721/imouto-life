
undefined4 FUN_0052eeb0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  bool bVar5;
  undefined1 local_6c [40];
  undefined4 local_44;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 0x931b8) == 1) {
    *(undefined4 *)(param_1 + 0x931b8) = 0;
    if (*(char *)(param_1 + 0x931c1) == '\b') {
      uVar3 = 1;
      FUN_005194a0(local_6c,0x10,1,0);
      if ((*(byte *)(param_1 + 0x93184) & 2) == 0) {
        cVar4 = '\x04';
      }
      else {
        cVar4 = (*(int *)(param_1 + 0x931e0) == 0xff) * '\x04' + '\x04';
      }
    }
    else {
      uVar3 = 0;
      cVar4 = '\0';
      bVar5 = (*(byte *)(param_1 + 0x93184) & 2) != 0;
      if (bVar5) {
        uVar1 = *(undefined4 *)(param_1 + 0x935fc);
      }
      else {
        uVar1 = 0x10;
      }
      FUN_005194a0(local_6c,uVar1,bVar5,!bVar5);
    }
    uVar1 = FUN_00516960();
    FUN_00516940(1);
    iVar2 = *(int *)(param_1 + 0x9318c);
    if ((*(byte *)(param_1 + 0x93184) & 1) != 0) {
      iVar2 = iVar2 * 2;
    }
    local_4 = 1;
    local_44 = 1;
    uVar3 = FUN_005243b0(local_6c,iVar2,*(undefined4 *)(param_1 + 0x93190),0,uVar3,cVar4,0,param_2);
    *(undefined4 *)(param_1 + 0x931b0) = uVar3;
    *(undefined4 *)(param_1 + 0x931b4) = 0xffffffff;
    if ((*(byte *)(param_1 + 0x93184) & 1) != 0) {
      iVar2 = *(int *)(param_1 + 0x9318c);
      uVar3 = FUN_00528eb0(0,iVar2,(float)iVar2,0,0,iVar2,(float)iVar2,*(int *)(param_1 + 0x93190),
                           (float)*(int *)(param_1 + 0x93190),uVar3,param_2);
      *(undefined4 *)(param_1 + 0x931b4) = uVar3;
    }
    FUN_00516940(uVar1);
    if (*(int *)(param_1 + 0x931b0) < 0) {
      return 0xffffffff;
    }
    FUN_00515720(*(int *)(param_1 + 0x931b0),param_1 + 0x931b8);
    FUN_005159a0(*(undefined4 *)(param_1 + 0x931b0),(int *)(param_1 + 0x93604),
                 (int *)(param_1 + 0x93608));
    *(float *)(param_1 + 0x9360c) = 1.0 / (float)*(int *)(param_1 + 0x93604);
    *(float *)(param_1 + 0x93610) = 1.0 / (float)*(int *)(param_1 + 0x93608);
    FUN_0052ee10(param_1,param_2);
  }
  return 0;
}

