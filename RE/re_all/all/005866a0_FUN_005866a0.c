
undefined4 FUN_005866a0(uint param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_490;
  int local_48c;
  int local_488;
  int local_484;
  int local_480;
  int local_47c;
  int local_478;
  int local_474;
  int local_470;
  int local_46c;
  int *local_468;
  int local_464;
  int local_460 [3];
  int local_454;
  int local_44c;
  undefined1 local_440 [1088];
  
  if (((((DAT_00cc47d0 != 0) && (-1 < (int)param_1)) && ((param_1 & 0x7c000000) == DAT_00cc47f8)) &&
      (((int)(param_1 & 0xffff) < DAT_00cc4800 &&
       (piVar1 = *(int **)(DAT_00cc47d4 + (param_1 & 0xffff) * 4), piVar1 != (int *)0x0)))) &&
     ((*piVar1 * 0x10000 == (param_1 & 0x3ff0000) && (piVar1[4] == 0)))) {
    local_468 = piVar1;
    if (param_3 == (int *)0x0) {
      FUN_00515880(param_1,&local_48c,&local_490);
      param_3 = local_460;
      local_460[0] = 0;
      local_460[2] = local_48c;
      local_460[1] = 0;
      local_454 = local_490;
    }
    else {
      local_48c = param_3[2] - *param_3;
      local_490 = param_3[3] - param_3[1];
    }
    iVar2 = FUN_00546c90(local_48c,local_490,param_2);
    if (-1 < iVar2) {
      if (*(char *)(piVar1[0x13] + 8) == '\0') {
        iVar2 = FUN_005229c0(param_3,local_440,param_1,0,0,1,0);
        if (iVar2 < 0) {
LAB_00586902:
          FUN_005421c0(param_2);
          return 0xffffffff;
        }
        FUN_0054eb60(0,0,local_48c,local_490,0,0,local_440,param_2);
        FUN_00517420();
      }
      else {
        piVar5 = piVar1 + 0x23;
        local_478 = 0;
        if (0 < piVar1[0x22]) {
          do {
            local_488 = piVar5[4];
            local_470 = param_3[2];
            local_480 = piVar5[8] + piVar5[4];
            local_484 = piVar5[5];
            local_47c = piVar5[5] + piVar5[9];
            iVar2 = *piVar5;
            local_44c = piVar5[1];
            iVar3 = piVar5[8] + iVar2;
            iVar4 = piVar5[9] + local_44c;
            if (((iVar2 < local_470) && (local_46c = *param_3, local_46c < iVar3)) &&
               ((local_464 = param_3[3], local_44c < local_464 &&
                (local_474 = param_3[1], local_474 < iVar4)))) {
              if (iVar2 < local_46c) {
                local_488 = local_488 + (local_46c - iVar2);
                iVar2 = iVar2 + (local_46c - iVar2);
              }
              if (local_470 < iVar3) {
                local_480 = local_480 + (local_470 - iVar3);
              }
              iVar3 = local_44c;
              if (local_44c < local_474) {
                local_484 = local_484 + (local_474 - local_44c);
                iVar3 = local_44c + (local_474 - local_44c);
              }
              if (local_464 < iVar4) {
                local_47c = local_47c + (local_464 - iVar4);
              }
              iVar4 = FUN_005229c0(&local_488,local_440,param_1,0,0,1,local_478);
              if (iVar4 < 0) goto LAB_00586902;
              FUN_0054eb60(0,0,local_480 - local_488,local_47c - local_484,iVar2,iVar3,local_440);
              FUN_00517420();
            }
            local_478 = local_478 + 1;
            piVar5 = piVar5 + 0x1e;
            if (local_468[0x22] <= local_478) {
              return 0;
            }
          } while( true );
        }
      }
      return 0;
    }
  }
  return 0xffffffff;
}

