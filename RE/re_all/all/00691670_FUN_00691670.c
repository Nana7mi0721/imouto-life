
undefined4 FUN_00691670(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = param_1;
  iVar4 = param_1[3];
  if (param_3 == 0) {
    *(undefined4 *)(*(int *)param_1[8] + 0x14) = 0x29;
    (*(code *)**(undefined4 **)param_1[8])((undefined4 *)param_1[8]);
  }
  iVar4 = iVar4 + param_3;
  uVar5 = ((1 << ((byte)param_3 & 0x1f)) - 1U & param_2) << (0x18U - (char)iVar4 & 0x1f) |
          param_1[2];
  while( true ) {
    if (iVar4 < 8) {
      piVar2[2] = uVar5;
      piVar2[3] = iVar4;
      return 1;
    }
    param_1._2_1_ = (char)(uVar5 >> 0x10);
    *(char *)*piVar2 = param_1._2_1_;
    iVar1 = piVar2[1];
    *piVar2 = *piVar2 + 1;
    piVar2[1] = iVar1 + -1;
    if ((iVar1 + -1 == 0) && (cVar3 = FUN_00691610(piVar2), cVar3 == '\0')) break;
    if (param_1._2_1_ == -1) {
      *(undefined1 *)*piVar2 = 0;
      iVar1 = piVar2[1];
      *piVar2 = *piVar2 + 1;
      piVar2[1] = iVar1 + -1;
      if ((iVar1 + -1 == 0) && (cVar3 = FUN_00691610(piVar2), cVar3 == '\0')) {
        return 0;
      }
    }
    iVar4 = iVar4 + -8;
    uVar5 = uVar5 << 8;
  }
  return 0;
}

