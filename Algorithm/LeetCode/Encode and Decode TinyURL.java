// 535. Encode and Decode TinyURL (https://leetcode.com/problems/encode-and-decode-tinyurl)

import java.util.*;
import java.util.UUID;

public class Codec {

    Map<String, String> codeUrl = new HashMap<>(), oriUrl = new HashMap<>();
    
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        if(oriUrl.containsKey(longUrl)) return oriUrl.get(longUrl);
        UUID uuid = UUID.randomUUID();
        String encodedUrl = "http://tinyurl.com/" + uuid.toString().substring(6);
        codeUrl.put(encodedUrl, longUrl);
        oriUrl.put(longUrl, encodedUrl);
        return encodedUrl;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return codeUrl.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));