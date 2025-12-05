/**
 * if_deep_blocks.p
 */
//&T-
ifdeepblocks;

begin
    var x : integer;
    x := 2;

    begin
        begin
            if x > 1 then
                begin
                    begin
                        print "deep block";
                    end
                end
            end if
        end
    end
end
end