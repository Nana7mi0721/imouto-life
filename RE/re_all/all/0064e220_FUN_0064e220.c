
undefined4 FUN_0064e220(undefined4 *param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = FUN_00653760(param_1,param_2,0);
  if (iVar1 == 0) {
    pcVar2 = s_pseudo__00a067b4;
    if (param_2 < 0x10000) {
      pcVar2 = &DAT_00f3fa48;
    }
    FUN_006512e0(param_1[0x9d],s_TIFFSetField_00a0678c,s__s__Unknown__stag__u_00a0679c,*param_1,
                 pcVar2,param_2);
    return 0;
  }
  if (((param_2 == 0x101) || ((*(byte *)(param_1 + 3) & 0x40) == 0)) ||
     (*(char *)(iVar1 + 0x1a) != '\0')) {
    return 1;
  }
  FUN_006512e0(param_1[0x9d],s_TIFFSetField_00a0678c,s__s__Cannot_modify_tag___s__while_00a06760,
               *param_1,*(undefined4 *)(iVar1 + 0x1c));
  return 0;
}

