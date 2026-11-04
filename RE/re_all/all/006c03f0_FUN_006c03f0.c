
/* WARNING: Removing unreachable block (ram,0x006c046f) */

undefined8 FUN_006c03f0(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  
  do {
    while( true ) {
      if (((-1 < param_4) && ((0 < param_4 || (param_3 != 0)))) &&
         ((param_4 < *(int *)(param_1 + 0x34) ||
          ((param_4 <= *(int *)(param_1 + 0x34) && (param_3 <= *(uint *)(param_1 + 0x30))))))) {
        return 0xffffffffffffffff;
      }
      uVar3 = FUN_006a87e0(param_1 + 0x40,param_2);
      if (-1 < (int)uVar3) break;
      uVar1 = *(uint *)(param_1 + 0x30);
      *(uint *)(param_1 + 0x30) = uVar1 - uVar3;
      *(uint *)(param_1 + 0x34) =
           (*(int *)(param_1 + 0x34) - ((int)uVar3 >> 0x1f)) - (uint)(uVar1 < uVar3);
    }
    if (uVar3 != 0) {
      uVar1 = *(uint *)(param_1 + 0x30);
      uVar2 = *(undefined8 *)(param_1 + 0x30);
      *(uint *)(param_1 + 0x30) = uVar3 + uVar1;
      *(uint *)(param_1 + 0x34) =
           ((int)uVar3 >> 0x1f) + *(int *)(param_1 + 0x34) + (uint)CARRY4(uVar3,uVar1);
      return uVar2;
    }
    if (param_3 == 0 && param_4 == 0) {
      return 0xffffffffffffffff;
    }
    if ((param_4 < 1) && (param_4 < 0)) {
LAB_006c048f:
      iVar4 = 0x800;
    }
    else {
      lVar5 = FUN_006c0540(param_1);
      uVar3 = (uint)lVar5;
      if (CONCAT44(param_4,param_3) <= lVar5) {
        return 0xffffffffffffffff;
      }
      iVar4 = (param_4 - (int)((ulonglong)lVar5 >> 0x20)) - (uint)(param_3 < uVar3);
      if ((0 < iVar4) || ((-1 < iVar4 && (0x7ff < param_3 - uVar3)))) goto LAB_006c048f;
      iVar4 = param_3 - uVar3;
    }
    iVar4 = FUN_006c0500(param_1,iVar4);
    if (iVar4 < 0) {
      return 0xffffffffffffff80;
    }
    if (iVar4 == 0) {
      if ((param_4 < 1) && (param_4 < 0)) {
        return 0xffffffffffffffff;
      }
      return 0xffffffffffffff77;
    }
  } while( true );
}

