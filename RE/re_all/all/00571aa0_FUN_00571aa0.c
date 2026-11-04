
int FUN_00571aa0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6,undefined4 param_7)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 local_890 [2192];
  
  if (((in_EAX != -1) && ((&DAT_00afed08)[in_EAX] != 0)) &&
     (iVar2 = FUN_0056d130(param_1,(&DAT_00afed08)[in_EAX] + 0x898), iVar2 == 0)) {
    *(int *)(&DAT_00afed08)[in_EAX] = *(int *)(&DAT_00afed08)[in_EAX] + 1;
    return in_EAX;
  }
  iVar2 = -1;
  iVar6 = 0;
  iVar3 = DAT_00b22da4;
  if (0 < DAT_00b22da4) {
    iVar5 = 0;
    do {
      piVar1 = (int *)(&DAT_00afed08)[iVar6];
      if (piVar1 == (int *)0x0) {
        iVar2 = iVar6;
      }
      else {
        iVar5 = iVar5 + 1;
        iVar3 = FUN_0056d130(piVar1 + 0x226,param_1);
        if (iVar3 == 0) {
          *piVar1 = *piVar1 + 1;
          return iVar6;
        }
        iVar3 = DAT_00b22da4;
      }
      iVar6 = iVar6 + 1;
    } while (iVar5 < iVar3);
  }
  if ((iVar3 != 0x1000) || (FUN_005714c0(), DAT_00b22da4 != 0x1000)) {
    if (iVar2 == -1) {
      iVar2 = 0;
      iVar3 = DAT_00afed08;
      while (iVar3 != 0) {
        iVar2 = iVar2 + 1;
        iVar3 = (&DAT_00afed08)[iVar2];
      }
    }
    FUN_0056d380(local_890,0,0x890);
    if (param_2 == 0) {
      if (param_6 == 1) {
        iVar3 = FUN_0056efd0(local_890,param_1,~-(uint)(DAT_00b22d90 != 1) & 0xb22d94,param_7);
        if (iVar3 < 0) {
          return -1;
        }
      }
      else {
        iVar3 = FUN_0056f400(local_890,param_1,~-(uint)(DAT_00b22d90 != 1) & 0xb22d94);
        if (iVar3 < 0) {
          return -1;
        }
      }
    }
    else {
      iVar3 = FUN_0056e970(local_890,param_2,param_3,param_4,param_5,
                           ~-(uint)(DAT_00b22d90 != 1) & 0xb22d94,param_1);
      if (iVar3 < 0) {
        return -1;
      }
    }
    puVar4 = (undefined4 *)
             FUN_0056e030(0xca8,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0xf75);
    (&DAT_00afed08)[iVar2] = (int)puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      FUN_0056d420(puVar4 + 2,local_890,0x890);
      *puVar4 = 1;
      FUN_0056cf70(puVar4 + 0x226,0x410,param_1);
      DAT_00b22da4 = DAT_00b22da4 + 1;
      return iVar2;
    }
    FUN_0056f750(local_890);
    FUN_0056f750(local_890);
    FUN_0056d380(local_890,0,0x890);
  }
  return -1;
}

