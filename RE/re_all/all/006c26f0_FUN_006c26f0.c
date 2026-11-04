
uint FUN_006c26f0(int param_1,undefined4 *param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  ulonglong uVar12;
  uint *local_448;
  uint local_444;
  uint local_440;
  uint local_43c;
  uint local_438;
  uint local_434;
  uint local_430;
  int local_42c;
  int local_428;
  int local_424;
  uint local_420;
  int local_41c;
  int local_418;
  int local_414;
  undefined4 local_410;
  uint local_40c;
  undefined4 local_408;
  undefined4 local_404;
  int local_400;
  uint local_3fc [255];
  
  uVar12 = CONCAT44(param_4,param_3);
  if (param_5 == 0) {
    return 0;
  }
  local_400 = *(int *)(param_1 + 0x14);
  local_428 = *(int *)(param_1 + 0x1c);
  if (local_400 == 0) {
    local_424 = 0;
  }
  else {
    local_424 = *(int *)(param_1 + 0x60);
  }
  iVar4 = *(int *)(local_424 * 0x160 + 0x28 + local_428);
  local_418 = iVar4;
LAB_006c2749:
  do {
    puVar1 = param_2;
    if (param_2 == (undefined4 *)0x0) {
      uVar12 = FUN_006c03f0(param_1,&local_410,*(undefined4 *)(param_1 + 0x38),
                            *(undefined4 *)(param_1 + 0x3c));
    }
    else {
      local_410 = *param_2;
      param_2 = (undefined4 *)0x0;
      local_40c = puVar1[1];
      local_408 = puVar1[2];
      local_404 = puVar1[3];
    }
    param_4 = (int)(uVar12 >> 0x20);
    param_3 = (uint)uVar12;
    if ((longlong)uVar12 < 0) {
      if (0x7fffffffffffffff < uVar12) {
        if ((longlong)uVar12 < -0x100000000) {
          return param_3;
        }
        if (param_3 != 0xffffffff) {
          return param_3;
        }
      }
      return 0xfffffffe;
    }
    if ((*(int *)(param_1 + 0x5c) < 3) || (iVar2 = FUN_006a8360(&local_410), iVar4 == iVar2)) {
      uVar5 = *(uint *)(param_1 + 0x78);
      *(uint *)(param_1 + 0x78) = uVar5 + local_40c;
      *(uint *)(param_1 + 0x7c) =
           *(int *)(param_1 + 0x7c) + ((int)local_40c >> 0x1f) + (uint)CARRY4(uVar5,local_40c);
    }
    else {
      iVar2 = FUN_006a8260(&local_410);
      if (iVar2 != 0) {
        if (param_6 == 0) {
          return 0xfffffffe;
        }
        if (3 < *(int *)(param_1 + 0x5c)) {
          FUN_006c26a0(param_1);
        }
      }
    }
    iVar2 = *(int *)(param_1 + 0x5c);
    iVar3 = iVar4;
    if (2 < iVar2) {
LAB_006c28e4:
      if ((iVar2 == 3) && (uVar5 = FUN_006c0f60(param_1), (int)uVar5 < 0)) {
        return uVar5;
      }
      FUN_006a89a0(param_1 + 0x88,&local_410);
      iVar4 = iVar3;
      if (3 < *(int *)(param_1 + 0x5c)) {
        local_448 = (uint *)FUN_006c0dc0(param_1,local_3fc);
        if (((int)local_448 < 0) &&
           (local_448 = (uint *)FUN_006c0dc0(param_1,local_3fc), param_7 == 0)) {
          return 0xfffffffd;
        }
        local_414 = *(int *)(param_1 + 0x21d4);
        if (0 < local_414) {
          local_440 = *(uint *)(param_1 + 0x6c);
          iVar4 = (local_414 + 0xf) * 0x20;
          local_42c = *(int *)(local_414 * 0x20 + 0x1dc + param_1);
          local_444 = *(uint *)(param_1 + 0x68);
          local_43c = *(uint *)(iVar4 + param_1);
          local_438 = *(uint *)(iVar4 + 4 + param_1);
          if ((local_444 & local_440) == 0xffffffff) {
            if (local_42c != 0) {
              *(undefined4 *)(param_1 + 0x21d4) = 0;
              iVar4 = local_418;
              goto LAB_006c2749;
            }
            iVar4 = 0xf00;
            iVar2 = local_428 + local_424 * 0x160;
            local_444 = *(uint *)(iVar2 + 0x20);
            local_440 = *(uint *)(iVar2 + 0x24);
            if ((local_43c & local_438) != 0xffffffff) {
              FUN_006bff30(&local_444,local_43c,local_438,-(int)local_448);
            }
            iVar3 = FUN_006c0c50(&local_420,local_444,local_440,*(undefined4 *)(iVar2 + 0x20),
                                 *(undefined4 *)(iVar2 + 0x24));
            if ((iVar3 == 0) && (-1 < local_41c)) {
              uVar5 = *(int *)(iVar2 + 0x34) - 0xf00;
              uVar5 = uVar5 & ((int)uVar5 < 0) - 1;
              iVar3 = (int)uVar5 >> 0x1f;
              if ((local_41c <= iVar3) && ((local_41c < iVar3 || (local_420 <= uVar5)))) {
                iVar4 = *(int *)(iVar2 + 0x34) - local_420;
              }
            }
            *(int *)(param_1 + 100) = iVar4;
          }
          iVar3 = local_414;
          iVar2 = local_424;
          iVar4 = local_42c;
          if (((local_43c & local_438) == 0xffffffff) &&
             (iVar9 = FUN_006bff30(&local_43c,local_444,local_440,local_448), iVar9 < 0)) {
            local_43c = *(uint *)(iVar2 * 0x160 + 0x18 + local_428);
            local_438 = *(uint *)(iVar2 * 0x160 + 0x1c + local_428);
          }
          if ((((iVar4 == 0) ||
               (iVar4 = FUN_006c0c50(&local_420,local_43c,local_438,local_444,local_440), iVar4 != 0
               )) || ((int)local_448 >> 0x1f < local_41c)) ||
             (((int)local_448 >> 0x1f <= local_41c && (local_448 <= local_420)))) {
            iVar4 = FUN_006bff30(&local_444,local_43c,local_438,-(int)local_448);
            if (iVar4 < 0) {
              local_444 = 0;
              local_440 = 0;
            }
            local_42c = 0;
            if (0 < iVar3) {
              puVar8 = local_3fc;
              puVar7 = (uint *)(param_1 + 0x200);
              local_42c = local_414;
              iVar4 = local_414;
              do {
                iVar2 = FUN_006bff30(&local_434,local_43c,local_438,-(int)local_448);
                if (iVar2 < 0) {
                  local_434 = 0;
                  local_430 = 0;
                }
                local_448 = (uint *)((int)local_448 - *puVar8);
                FUN_006bff30(&local_434,local_434,local_430,*puVar8);
                *puVar7 = local_434;
                puVar7[1] = local_430;
                puVar7 = puVar7 + 8;
                puVar8 = puVar8 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
          }
          else {
            local_434 = local_444;
            local_430 = local_440;
            local_42c = 0;
            if (0 < iVar3) {
              local_448 = local_3fc;
              puVar7 = (uint *)(param_1 + 0x200);
              do {
                uVar5 = *local_448;
                iVar2 = (int)uVar5 >> 0x1f;
                bVar10 = uVar5 < local_420;
                local_420 = uVar5 - local_420;
                bVar11 = SBORROW4(iVar2,local_41c);
                iVar4 = iVar2 - local_41c;
                local_41c = iVar4 - (uint)bVar10;
                if ((local_41c < 0) ||
                   ((local_41c == 0 || bVar11 != SBORROW4(iVar4,(uint)bVar10) && (local_420 == 0))))
                {
                  FUN_006bff30(&local_434,local_434,local_430,uVar5);
                }
                else {
                  if ((iVar2 < local_41c) || ((iVar2 <= local_41c && (uVar5 < local_420)))) break;
                  local_434 = local_43c;
                  local_430 = local_438;
                  puVar7[-1] = 1;
                }
                *puVar7 = local_434;
                puVar7[1] = local_430;
                FUN_006c0c50(&local_420,local_43c,local_438,local_434,local_430);
                local_42c = local_42c + 1;
                puVar7 = puVar7 + 8;
                local_448 = local_448 + 1;
              } while (local_42c < local_414);
            }
          }
          *(uint *)(param_1 + 0x68) = local_444;
          *(uint *)(param_1 + 0x6c) = local_440;
          *(ulonglong *)(param_1 + 0x70) = uVar12;
          *(int *)(param_1 + 0x21d4) = local_42c;
          if (0 < local_42c) goto LAB_006c2d75;
          iVar4 = local_418;
        }
      }
      goto LAB_006c2749;
    }
    if (local_400 == 0) {
      iVar2 = local_428 + 0x14c;
      iVar3 = local_428 + 0x2c;
      do {
        uVar5 = FUN_006c0350(param_1,iVar3,iVar2,0,0,0,&local_410);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        uVar5 = FUN_006c08d0(param_1,local_428,&local_410);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        iVar4 = *(int *)(param_1 + 0x1d8);
        *(int *)(*(int *)(param_1 + 0x1c) + 0x28) = iVar4;
        *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
        local_418 = iVar4;
      } while (0 < (int)uVar5);
      if (0 < *(int *)(param_1 + 0x21d4)) {
        uVar5 = FUN_006c0f60(param_1);
        if (-1 < (int)uVar5) {
LAB_006c2d75:
          uVar5 = 1;
        }
        return uVar5;
      }
    }
    else {
      iVar3 = FUN_006a8360(&local_410);
      iVar2 = *(int *)(param_1 + 0x18);
      iVar9 = 0;
      if (0 < iVar2) {
        piVar6 = (int *)(local_428 + 0x28);
        do {
          if (*piVar6 == iVar3) {
            if (iVar9 < iVar2) {
              *(int *)(param_1 + 0x60) = iVar9;
              local_424 = iVar9;
              local_418 = iVar3;
              FUN_006a8d60(param_1 + 0x88,iVar3);
              *(undefined4 *)(param_1 + 0x5c) = 3;
              iVar4 = local_428 + iVar9 * 0x160;
              if ((param_4 <= *(int *)(iVar4 + 0xc)) &&
                 ((param_4 < *(int *)(iVar4 + 0xc) || (param_3 <= *(uint *)(iVar4 + 8))))) {
                param_7 = 1;
                *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(iVar4 + 0x20);
                *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(iVar4 + 0x24);
                *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
                *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
                *(undefined4 *)(param_1 + 100) = *(undefined4 *)(iVar4 + 0x34);
              }
              iVar2 = *(int *)(param_1 + 0x5c);
              goto LAB_006c28e4;
            }
            break;
          }
          iVar9 = iVar9 + 1;
          piVar6 = piVar6 + 0x58;
        } while (iVar9 < iVar2);
      }
    }
  } while( true );
}

