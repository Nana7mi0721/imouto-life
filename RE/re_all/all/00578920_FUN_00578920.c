
int __thiscall
FUN_00578920(undefined4 param_1,double param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,int param_9,uint param_10,undefined4 param_11)

{
  bool bVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  undefined1 *local_430;
  undefined1 *local_424;
  undefined1 local_420 [1056];
  
  local_424 = (undefined1 *)0x0;
  if (((int)in_EAX < 0) || (in_EAX < 0x400)) {
    local_430 = local_420;
  }
  else {
    local_424 = (undefined1 *)
                FUN_0056e030(in_EAX + 0x20,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",
                             0x152f);
    if (local_424 == (undefined1 *)0x0) {
      in_EAX = 0x400;
      local_430 = local_420;
    }
    else {
      local_430 = local_424;
    }
  }
  iVar9 = 0;
  uVar2 = FUN_00573310();
  if (uVar2 == 0) goto LAB_00578eec;
  iVar3 = FUN_0057ab10(param_2);
  bVar1 = false;
  if ((((iVar3 == 1) || (iVar3 == 2)) || (iVar3 == 4)) || (iVar3 == 0x200)) {
    bVar1 = true;
    if ((iVar3 == 1) || (iVar3 == 2)) {
      bVar10 = false;
    }
    else {
      bVar10 = iVar3 == 4;
    }
  }
  else {
    bVar10 = false;
    if (param_2 < 0.0) {
      param_2 = -param_2;
      bVar10 = true;
    }
  }
  if (param_8 < 0) {
    param_8 = 0;
  }
  if (param_5 != 0) {
    param_4 = 0;
  }
  if (param_6 != 0) {
    param_7 = 0;
  }
  if (bVar10) {
    param_7 = 0;
    param_6 = 0;
  }
  if (bVar1) {
    switch(param_3 + -8) {
    case 0:
    case 1:
      puVar4 = (undefined1 *)FUN_00577d70(in_EAX,param_3 == 9);
      break;
    case 2:
      puVar4 = (undefined1 *)FUN_00577cb0(param_1,1);
      break;
    case 3:
    case 4:
      puVar4 = (undefined1 *)FUN_00577cb0(param_1,0);
      break;
    case 5:
    case 6:
      puVar4 = (undefined1 *)FUN_00577db0(in_EAX,param_3 == 0xe);
      break;
    default:
      goto switchD_00578a88_default;
    }
  }
  else {
    switch(param_3 + -8) {
    case 0:
    case 1:
      puVar4 = (undefined1 *)FUN_005780e0(param_2,param_1,param_3 == 9,local_430);
      break;
    case 2:
      puVar4 = (undefined1 *)FUN_00578390(param_2,param_1,in_EAX,local_430);
      break;
    case 3:
    case 4:
      puVar4 = (undefined1 *)FUN_005785c0(param_2,param_1,param_3 == 0xc,local_430);
      break;
    case 5:
    case 6:
      puVar4 = (undefined1 *)FUN_00577df0(param_2,param_1,param_3 == 0xe,local_430);
      break;
    default:
switchD_00578a88_default:
      puVar4 = local_424;
    }
  }
  if (((param_7 != 0) || (param_6 != 0)) || (bVar10)) {
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  param_8 = param_8 - (int)(puVar4 + iVar3);
  iVar3 = param_8 >> 0x1f;
  if (param_5 != 0) {
    if (((bVar10) || (param_6 != 0)) || (iVar5 = iVar9, param_7 != 0)) {
      iVar5 = FUN_00573310();
      if (((iVar5 == 0) || (param_10 < iVar5 + uVar2)) || (iVar9 = iVar5, param_10 - iVar5 <= uVar2)
         ) goto LAB_00578eec;
    }
    iVar7 = 0;
    if (0 < (int)puVar4) {
      uVar8 = param_10 - iVar5;
      do {
        iVar6 = FUN_00573310();
        iVar9 = iVar5;
        if ((iVar6 == 0) || (uVar8 < iVar6 + uVar2)) goto LAB_00578eec;
        iVar5 = iVar5 + iVar6;
        uVar8 = param_10 - iVar5;
        iVar9 = iVar5;
        if (uVar8 <= uVar2) goto LAB_00578eec;
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)puVar4);
    }
    iVar9 = iVar5;
    if (0 < param_8) {
      iVar9 = FUN_00577c20(param_8,iVar3,0x20,iVar5 + param_9,param_10 - iVar5,param_11);
      iVar9 = iVar5 + iVar9;
    }
    goto LAB_00578eec;
  }
  if (param_4 == 0) {
    if ((0 < param_8) &&
       (iVar9 = FUN_00577c20(param_8,iVar3,0x20,param_9,param_10,param_11),
       param_10 - iVar9 <= uVar2)) goto LAB_00578eec;
    if ((bVar10) || ((param_6 != 0 || (param_7 != 0)))) {
      iVar3 = FUN_00573310();
      if ((iVar3 == 0) || (param_10 - iVar9 < iVar3 + uVar2)) goto LAB_00578eec;
      iVar9 = iVar9 + iVar3;
      goto LAB_00578e91;
    }
  }
  else {
    if (((bVar10) || (param_6 != 0)) || (iVar5 = iVar9, param_7 != 0)) {
      iVar5 = FUN_00573310();
      if (((iVar5 == 0) || (param_10 < iVar5 + uVar2)) || (iVar9 = iVar5, param_10 - iVar5 <= uVar2)
         ) goto LAB_00578eec;
    }
    iVar9 = iVar5;
    if (0 < param_8) {
      iVar9 = FUN_00577c20(param_8,iVar3,0x30,iVar5 + param_9,param_10 - iVar5,param_11);
      iVar9 = iVar5 + iVar9;
LAB_00578e91:
      if (param_10 - iVar9 <= uVar2) goto LAB_00578eec;
    }
  }
  iVar3 = 0;
  if (0 < (int)puVar4) {
    uVar8 = param_10 - iVar9;
    while ((iVar5 = FUN_00573310(), iVar5 != 0 && (iVar5 + uVar2 <= uVar8))) {
      iVar9 = iVar9 + iVar5;
      uVar8 = param_10 - iVar9;
      if ((uVar8 <= uVar2) || (iVar3 = iVar3 + 1, (int)puVar4 <= iVar3)) break;
    }
  }
LAB_00578eec:
  if (local_424 != (undefined1 *)0x0) {
    FUN_0056e1d0();
  }
  return iVar9;
}

