
undefined4 FUN_00668fc0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 local_80 [128];
  
  if (param_2 == (char *)0x0) {
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x20000;
  }
  else {
    iVar6 = 0;
    do {
      iVar2 = FUN_006696e0(0);
      if (param_2[iVar6] != *(char *)(iVar2 + iVar6)) {
        *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x20000;
      }
      iVar2 = FUN_006696e0(0);
      pcVar3 = (char *)(iVar2 + iVar6);
      iVar6 = iVar6 + 1;
    } while (*pcVar3 != '\0');
  }
  if ((*(uint *)(param_1 + 0x78) & 0x20000) == 0) {
    return 1;
  }
  if (param_2 != (char *)0x0) {
    cVar1 = *param_2;
    pcVar3 = (char *)FUN_006696e0(0);
    if ((cVar1 == *pcVar3) &&
       ((cVar1 != '1' ||
        ((iVar6 = FUN_006696e0(0), param_2[2] == *(char *)(iVar6 + 2) &&
         (iVar6 = FUN_006696e0(0), param_2[3] == *(char *)(iVar6 + 3))))))) {
      if (*param_2 != '0') {
        return 1;
      }
      if ('8' < param_2[2]) {
        return 1;
      }
    }
  }
  uVar4 = FUN_00668650(local_80,0x80,0,s_Application_built_with_libpng__00a0bcbc);
  uVar4 = FUN_00668650(local_80,0x80,uVar4,param_2);
  uVar4 = FUN_00668650(local_80,0x80,uVar4,s_but_running_with_00a0bca8);
  uVar5 = FUN_006696e0(0);
  FUN_00668650(local_80,0x80,uVar4,uVar5);
  FUN_006687b0(param_1,local_80);
  return 0;
}

