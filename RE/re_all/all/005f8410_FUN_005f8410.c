
/* WARNING: Removing unreachable block (ram,0x005f853b) */
/* WARNING: Removing unreachable block (ram,0x005f8599) */

int FUN_005f8410(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
                uint param_6,int param_7,int param_8,void *param_9,int param_10)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  uint local_28;
  int local_24;
  undefined1 local_10 [4];
  uint local_c;
  uint local_4;
  
  lVar2 = CONCAT44(param_5,param_4);
  local_28 = param_6;
  local_24 = param_7;
  lVar1 = CONCAT44(param_5,param_4);
  lVar3 = CONCAT44(param_7,param_6);
  if ((param_5 <= param_7) &&
     ((lVar1 = lVar2, lVar2 = CONCAT44(param_7,param_6), param_5 < param_7 ||
      (lVar3 = CONCAT44(param_7,param_6), lVar2 = CONCAT44(param_7,param_6), param_4 < param_6)))) {
    do {
      iVar4 = (local_24 - (int)((ulonglong)lVar1 >> 0x20)) - (uint)(local_28 < (uint)lVar1);
      if ((0 < iVar4) || ((lVar7 = lVar1, -1 < iVar4 && (0xffff < local_28 - (uint)lVar1)))) {
        lVar7 = __alldiv(lVar1 + CONCAT44(local_24,local_28),2,0);
      }
      param_5 = (int)((ulonglong)lVar7 >> 0x20);
      iVar4 = FUN_006a9a90(param_1,lVar7);
      if (iVar4 != 0) {
        return iVar4;
      }
      lVar8 = FUN_005f7ef0(param_1,local_10,0xffffffff,0xffffffff);
      if (lVar8 == -0x80) {
        return -0x80;
      }
      lVar3 = lVar2;
      if ((lVar8 < 0) || (iVar4 = FUN_005f83d0(local_10,param_8,param_9), iVar4 == 0)) {
        local_24 = param_5;
        local_28 = (uint)lVar7;
        if (-1 < lVar8) {
          lVar3 = lVar8;
        }
      }
      else {
        lVar1 = lVar8 + CONCAT44(((int)local_4 >> 0x1f) + ((int)local_c >> 0x1f) +
                                 (uint)CARRY4(local_4,local_c),local_4 + local_c);
      }
      lVar2 = lVar3;
    } while (lVar1 < CONCAT44(local_24,local_28));
  }
  param_9 = (void *)0x0;
  param_8 = 0;
  iVar4 = FUN_006a9a90(param_1,lVar3);
  if ((iVar4 == 0) &&
     (iVar4 = FUN_005f82a0(param_1,&param_9,&param_8), iVar6 = param_10, iVar4 == 0)) {
    if ((lVar1 < CONCAT44(param_7,param_6)) && (param_8 != 0)) {
      iVar4 = FUN_005f8410(param_1,lVar3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc)
                           ,param_6,param_7,param_9,param_8,param_10 + 1);
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    else {
      iVar4 = param_10 + 1;
      *(int *)(param_1 + 0x34) = iVar4;
      pvVar5 = _malloc(iVar4 * 8 + 8);
      *(void **)(param_1 + 0x38) = pvVar5;
      *(int *)((int)pvVar5 + iVar4 * 8) = (int)lVar1;
      *(int *)((int)pvVar5 + iVar4 * 8 + 4) = (int)((ulonglong)lVar1 >> 0x20);
      iVar6 = param_10;
    }
    if (param_9 != (void *)0x0) {
      _free(param_9);
    }
    iVar4 = *(int *)(param_1 + 0x38);
    *(undefined4 *)(iVar4 + iVar6 * 8) = param_2;
    *(undefined4 *)(iVar4 + 4 + iVar6 * 8) = param_3;
    iVar4 = 0;
  }
  return iVar4;
}

